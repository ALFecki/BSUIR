using Microsoft.Maui.Graphics.Text;

namespace lab_1;


public partial class MainPage : ContentPage {


    delegate double Operation(double first, double second);

    Operation CurrentOperation;

    double FirstNumber = 0;
    double SecondNumber = 0;
    double ResultNumber = 0;
    double MemoryNumber = 0;
    bool isError = false;
    bool EqualClicked = false;



    public MainPage() {
        InitializeComponent();
    }

    public void onMemoryStoreClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        MemoryNumber = double.Parse(Result.Text);
    }

    public void onMemoryAddClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        MemoryNumber += double.Parse(Result.Text);
    }

    public void onMemorySubClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        MemoryNumber -= double.Parse(Result.Text);
    }

    public void onMemoryClearClicked(object sender, EventArgs e) {
        MemoryNumber = 0;
    }

    public void onMemoryRecallClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        Result.Text = MemoryNumber.ToString();
    }

    public void onNumberClicked(object sender, EventArgs e) {
        var button = (Button)sender;
        var number = button.Text;
        if (isError) {
            ClearLabels();
            Result.Text = number;
            return;
        } else if (Result.Text == "0") {
            Result.Text = number;
            return;
        } else if (CurrentOperation != null && FirstNumber.ToString() == Result.Text) {
            Result.Text = "";
        }
        Result.Text += number;

    }

    public void onOperationClicked(object sender, EventArgs e) {
        var button = (Button)sender;
        var operation = button.Text;
        if (isError) {
            ClearLabels();
        }
        if (CurrentOperation == null) {
            FirstNumber = double.Parse(Result.Text);
            CurrentOperation = ParseOperation(operation);
            if (CurrentOperation == Power) {
                Expression.Text = $"{FirstNumber} ^ ";
                return;
            }
            Expression.Text = $"{FirstNumber} {operation} ";
            return;
        }
        if (CurrentOperation != null && EqualClicked) {
            CurrentOperation = ParseOperation(operation);
            if (CurrentOperation == Power) {
                Expression.Text = $"{FirstNumber} ^ ";
                return;
            }
            Expression.Text = $"{ResultNumber} {operation} ";
            EqualClicked = false;
            return;
        }
        SecondNumber = double.Parse(Result.Text);
        ResultNumber = Calculate(FirstNumber, SecondNumber, CurrentOperation);
        Result.Text = ResultNumber.ToString();
        FirstNumber = ResultNumber;
        CurrentOperation = ParseOperation(operation);
        if (CurrentOperation == Power) {
            Expression.Text = $"{FirstNumber} ^ ";
            return;
        }
        Expression.Text = $"{FirstNumber} {operation} ";

    }


    public void onEqualClicked(object sender, EventArgs e) {
        if (CurrentOperation == null) {
            return;
        }
        if (EqualClicked) {
            FirstNumber = ResultNumber;
            ResultNumber = Calculate(FirstNumber, SecondNumber, CurrentOperation);
        } else {
            EqualClicked = true;
            SecondNumber = double.Parse(Result.Text);
            ResultNumber = Calculate(FirstNumber, SecondNumber, CurrentOperation);
        }
        if (isError) {
            return;
        }
        Expression.Text += $" {SecondNumber} =";
        Result.Text = ResultNumber.ToString();
        FirstNumber = ResultNumber;
    }


    private Operation ParseOperation(string operation) {
        switch (operation) {
            case "+":
                return Add;
            case "-":
                return Sub;
            case "*":
                return Mul;
            case "/":
                return Div;
            case "xʸ":
                return Power;
            default:
                return null;
        }
    }

    private double Calculate(double firstNumber, double secondNumber, Operation operation) {
        try {
            return operation.Invoke(firstNumber, secondNumber);
        } catch (OverflowException) {
            Result.Text = "Overflow";
            isError = true;
            return 0;
        } catch (DivideByZeroException) {
            Result.Text = "Divide by zero";
            isError = true;
            return 0;
        } catch (NotANumberException) {
            Result.Text = "Not a number";
            isError = true;
            return 0;
        }
    }

    private double Add(double firstNumber, double secondNumber) {
        Expression.Text = $"{firstNumber} + ";
        var result = firstNumber + secondNumber;
        if (result >= double.MaxValue) {
            isError = true;
            throw new OverflowException();
        }
        return result;
    }

    private double Sub(double firstNumber, double secondNumber) {
        Expression.Text = $"{firstNumber} - ";
        var result = firstNumber - secondNumber;
        if (result <= double.MinValue) {
            isError = true;
            throw new OverflowException();
        }
        return result;
    }

    private double Mul(double firstNumber, double secondNumber) {
        Expression.Text = $"{firstNumber} * ";
        var result = firstNumber * secondNumber;
        if (result >= double.MaxValue) {
            isError = true;
            throw new OverflowException();
        }
        return result;
    }

    private double Div(double firstNumber, double secondNumber) {
        Expression.Text = $"{firstNumber} / ";
        if (firstNumber ==0 && secondNumber == 0) {
            isError = true;
            throw new NotANumberException();
        }
        if (secondNumber == 0) {
            isError = true;
            throw new DivideByZeroException();
        }
        return firstNumber / secondNumber;
    }

    private double Power(double firstNumber, double secondNumber) {
        Expression.Text = $"{firstNumber} ^ ";
        var result = Math.Pow(firstNumber, secondNumber);
        if (result >= double.MaxValue) {
            isError = true;
            throw new OverflowException();
        }
        return result;
    }

    private void onReverseClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        try {
            if (CurrentOperation == null) {
                FirstNumber = double.Parse(Result.Text);
                if (FirstNumber == 0) {
                    throw new DivideByZeroException();
                }
                ResultNumber = 1 / FirstNumber;
                Expression.Text = $"1 / {FirstNumber} =";
                Result.Text = ResultNumber.ToString();
                FirstNumber = ResultNumber;
                return;
            } else if (CurrentOperation != null && EqualClicked) {
                if (FirstNumber == 0) {
                    throw new DivideByZeroException();
                }
                ResultNumber = 1 / FirstNumber;
                Expression.Text = $"1 / {FirstNumber} =";
                Result.Text = ResultNumber.ToString();
                FirstNumber = ResultNumber;
                return;
            } else {
                SecondNumber = double.Parse(Result.Text);
                if (SecondNumber == 0) {
                    throw new DivideByZeroException();
                }
                SecondNumber = 1 / SecondNumber;
                Result.Text = SecondNumber.ToString();
            }
        } catch (DivideByZeroException) {
            Result.Text = "Divide by zero";
            isError = true;
        }
    }

    private void onSqrClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }

        try {
            if (CurrentOperation == null) {
                FirstNumber = double.Parse(Result.Text);
                ResultNumber = FirstNumber * FirstNumber;
                if (ResultNumber >= double.MaxValue) {
                    isError = true;
                    throw new OverflowException();
                }
                Expression.Text = $"sqr({FirstNumber}) =";
                Result.Text = ResultNumber.ToString();
                FirstNumber = ResultNumber;
                return;
            } else if (CurrentOperation != null && EqualClicked) {
                ResultNumber = FirstNumber * FirstNumber;
                if (ResultNumber >= double.MaxValue) {
                    isError = true;
                    throw new OverflowException();
                }
                Expression.Text = $"sqr({FirstNumber}) =";
                Result.Text = ResultNumber.ToString();
                FirstNumber = ResultNumber;
                return;
            } else {
                SecondNumber = double.Parse(Result.Text);
                SecondNumber = SecondNumber * SecondNumber;
                Result.Text = SecondNumber.ToString();
            }
        } catch (OverflowException) {
            Result.Text = "Overflow";
            isError = true;
        }
    }

    private void onSqrtClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        if (CurrentOperation == null) {
            FirstNumber = double.Parse(Result.Text);
            ResultNumber = Math.Sqrt(FirstNumber);
            Expression.Text = $"sqrt({FirstNumber}) =";
            Result.Text = ResultNumber.ToString();
            FirstNumber = ResultNumber;
            return;
        } else if (CurrentOperation != null && EqualClicked) {
            ResultNumber = Math.Sqrt(FirstNumber);
            Expression.Text = $"sqrt({FirstNumber}) =";
            Result.Text = ResultNumber.ToString();
            FirstNumber = ResultNumber;
            return;
        } else {
            SecondNumber = double.Parse(Result.Text);
            SecondNumber = Math.Sqrt(SecondNumber);
            Result.Text = SecondNumber.ToString();
        }
    }

    private void onPercentClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        if (CurrentOperation == null) {
            ClearLabels();
            return;
        } else if (CurrentOperation != null && EqualClicked) {
            ResultNumber = ResultNumber * (ResultNumber / 100);
            Expression.Text = "";
            Result.Text = ResultNumber.ToString();
            FirstNumber = ResultNumber;
            return;
        } else {
            SecondNumber = double.Parse(Result.Text);
            SecondNumber = FirstNumber * SecondNumber / 100;
            ResultNumber = Calculate(FirstNumber, SecondNumber, CurrentOperation);
            Expression.Text += $" {SecondNumber} =";
            Result.Text = ResultNumber.ToString();
            FirstNumber = ResultNumber;
        }
    }

    private void onPowerClicked(object sender, EventArgs e) {
        if (isError) {
            ClearLabels();
        }
        if (CurrentOperation == null) {
            FirstNumber = double.Parse(Result.Text);
            CurrentOperation = Power;
            Expression.Text = $"{FirstNumber} ^ ";
            Result.Text = "0";
            return;
        } else if (CurrentOperation != null && EqualClicked) {
            FirstNumber = ResultNumber;
            CurrentOperation = Power;
            Expression.Text = $"{FirstNumber} ^ ";
            Result.Text = "0";
            return;
        } else {
            SecondNumber = double.Parse(Result.Text);
            ResultNumber = Calculate(FirstNumber, SecondNumber, CurrentOperation);
            if (isError) {
                return;
            }
            CurrentOperation = Power;
            Expression.Text = $"{FirstNumber} ^ {SecondNumber} =";
            Result.Text = "0";
            FirstNumber = ResultNumber;

        }
    }



    private void onClearResultClicked(object sender, EventArgs e) {
        Result.Text = "0";
    }

    private void onClearClicked(object sender, EventArgs e) {
        ClearLabels();
    }

    private void onBackspaceClicked(object sender, EventArgs e) {
        if (Result.Text.Length == 1) {
            Result.Text = "0";
            return;
        }
        Result.Text = Result.Text.Remove(Result.Text.Length - 1);
    }

    private void onDotClicked(object sender, EventArgs e) {
        if (Result.Text.Contains(",")) {
            return;
        }
        Result.Text += ",";
    }

    private void onSignClicked(object sender, EventArgs e) {
        if (Result.Text == "0") {
            return;
        }
        if (Result.Text.Contains("-")) {
            Result.Text = Result.Text.Remove(0, 1);
        } else {
            Result.Text = "-" + Result.Text;
        }
    }

    private void ClearLabels() {
        Result.Text = "0";
        Expression.Text = "";
        FirstNumber = 0;
        SecondNumber = 0;
        ResultNumber = 0;
        CurrentOperation = null;
        EqualClicked = false;
        isError = false;
    }

}


class OverflowException : Exception {
    public OverflowException() : base() { }

}

class DivideByZeroException : Exception {
    public DivideByZeroException() : base() { }
}

class NotANumberException : Exception {
    public NotANumberException() : base() { }
}