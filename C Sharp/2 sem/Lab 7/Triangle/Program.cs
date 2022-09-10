using Triangle_1;

namespace Triangle_1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Triangle triangle = new Triangle(3.5, 5.6, 7.6);
            Triangle triangle1 = new Triangle(1.2, 5.6, 2.8);
            Console.WriteLine("");
            Triangle triangle2 = new Triangle(4.76, 8.78, 7.85);

            Console.WriteLine(triangle2.Perimeter());
            Console.WriteLine("");
            Console.WriteLine(triangle.Area());
            Console.WriteLine("");
            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

            Console.WriteLine(triangle2);
            Console.WriteLine("");

            triangle++;
            triangle1--;
            triangle2 -= 2;

            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

            Console.WriteLine(triangle2);
            Console.WriteLine("");

            triangle /= 3;
            triangle1 *= 2;

            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

        }
    }
}


