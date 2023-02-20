using System;

namespace lab_1;

public partial class ProgressBar : ContentPage {

    private Progress<double> progress;
    private CancellationTokenSource cancellationToken = default(CancellationTokenSource);
    public ProgressBar() {
        InitializeComponent();
        progress = new((val) => {
            BarForIntegral.Progress = val;
            Percentage.Text = $"{Math.Round(val * 100, 2)} %";
        });
    }


    private async void OnStartButtonClicked(object sender, EventArgs e) {
        var integral = new Integral(progress);
        cancellationToken = new CancellationTokenSource();
        ResultLabel.Text = "Calculating...";
        var result = await Task.Run(() => integral.Calculate(cancellationToken.Token));
        if (double.IsNaN(result)) {
            ResultLabel.Text = "Canceled";
            return;
        }
        ResultLabel.Text = result.ToString();
    }

    private void OnCancelButtonClicked(object sender, EventArgs e) {
        cancellationToken.Cancel();
    }
}


public class Integral {
    private IProgress<double> progress;

    public Integral(IProgress<double> progress) {
        this.progress = progress;
    }

    public double Calculate(CancellationToken token) {
        double delta = 0.0000001;
        double result = 0;
        double progressInfo = 0;
        try {

            for (double i = 0; i < 1; i += delta) {

                result += Math.Sin(i + delta / 2.0) * delta;
                if (Math.Round(i, 2) != progressInfo) {
                    token.ThrowIfCancellationRequested();
                    progressInfo = Math.Round(i, 2);
                    progress.Report(progressInfo);
                }
                Task.Delay(50);
            }
            progress.Report(progressInfo);
            return result;
        } catch (OperationCanceledException) {

            return double.NaN;
        }
    }


}