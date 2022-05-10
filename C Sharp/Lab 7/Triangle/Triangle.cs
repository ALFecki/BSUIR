namespace Triangle_1
{
    public class Triangle
    {
        private double Parameters;

        private double A, B, C;

        public double a
        {
            get
            {
                return A;
            }
            set
            {
                A = value;
            }
        }

        public double b
        {
            get
            {
                return B;
            }
            set
            {
                B = value;
            }
        }

        public double c
        {
            get
            {
                return C;
            }
            set
            {
                C = value;
            }
        }

        public double this[int index]
        {
            get
            {
                switch (index)
                {
                    case 0:
                        return a;
                    case 1:
                        return b;
                    case 2:
                        return c;
                    case 3:
                        return Perimeter();
                    case 4:
                        return Area();
                    default:
                        throw new IndexOutOfRangeException();
                }
            }
            set
            {
                switch (index)
                {
                    case 0:
                        a = value;
                        break;
                    case 1:
                        b = value;
                        break;
                    case 2:
                        c = value;
                        break;
                    default:
                        throw new IndexOutOfRangeException();
                }
            }
        }

        public Triangle()
        {
            a = 10;
            b = 10;
            c = 10;
        }

        public Triangle(double A_, double B_, double C_)
        {
            if (A_ + B_ < C_ || A_ + C_ < B_ || B_ + C_ < A_)
            {
                Console.WriteLine("Triangle doesn't exist");
                A = 8;
                B = 8;
                C = 8;
            }
            else
            {
                a = A_;
                b = B_;
                c = C_;
            }
        }

        public double Perimeter()
        {
            return A + B + C;
        }

        public double Area()
        {
            double p = (A + B + C) / 2;
            return Math.Sqrt(p * (p - A) * (p - B) * (p - C));
        }

        public override string ToString()
        {
            string s = $"A = {A}, B = {B}, C = {C}, Perimeter = {Perimeter()}, Square = {Area()}";
            return s;
        }

        public static Triangle operator ++(Triangle temp)
        {
            return new Triangle(temp.a + 1, temp.b + 1, temp.c + 1);
        }

        public static Triangle operator --(Triangle temp)
        {
            temp = new Triangle(temp.a - 1, temp.b - 1, temp.c - 1);
            return temp;
        }

        public static Triangle operator +(Triangle temp, double value)
        {
            return new Triangle(temp.a + value, temp.b + value, temp.c + value);
        }

        public static Triangle operator -(Triangle temp, double value)
        {
            return new Triangle(temp.a - value, temp.b - value, temp.c - value);
        }

        public static Triangle operator *(Triangle temp, double value)
        {

            return new Triangle(temp.a * value, temp.b * value, temp.c * value);
        }

        public static Triangle operator /(Triangle temp, double value)
        {
            return new Triangle(temp.a / value, temp.b / value, temp.c / value);
        }

        public static bool operator ==(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() == temp2.Area();
        }

        public static bool operator !=(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() != temp2.Area();
        }

        public static bool operator >(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() > temp2.Area();
        }

        public static bool operator <(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() < temp2.Area();
        }

        public static bool operator >=(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() >= temp2.Area();
        }

        public static bool operator <=(Triangle temp1, Triangle temp2)
        {
            return temp1.Area() <= temp2.Area();
        }

        public static bool operator false(Triangle temp)
        {
            return temp.A == temp.C && temp.B == temp.C;
        }

        public static bool operator true(Triangle temp)
        {
            return temp.A != temp.C && temp.B != temp.C;
        }

        public static explicit operator double(Triangle temp)
        {
            return temp.Area();
        }

        public static implicit operator Triangle(double value)
        {
            return new Triangle(value, value, value);
        }
    }
}
