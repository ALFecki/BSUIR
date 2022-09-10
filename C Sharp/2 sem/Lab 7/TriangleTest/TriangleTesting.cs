using Microsoft.VisualStudio.TestTools.UnitTesting;
using Triangle_1;
using System;


namespace TriangleTest
{
    [TestClass]
    public class TriangleTesting
    {
        [TestMethod]
        public void TestOperationPlus()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test += 2;
                Assert.AreEqual(test.a, a[i] + 2);
                Assert.AreEqual(test.b, b[i] + 2);
                Assert.AreEqual(test.c, c[i] + 2);
            }

        }

        [TestMethod]
        public void TestOperationMinus()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test -= 1;
                Assert.AreEqual(test.a, a[i] - 1);
                Assert.AreEqual(test.b, b[i] - 1);
                Assert.AreEqual(test.c, c[i] - 1);
            }
        }

        [TestMethod]
        public void TestOperationMultiply()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test *= 2;
                Assert.AreEqual(test.a, a[i] * 2);
                Assert.AreEqual(test.b, b[i] * 2);
                Assert.AreEqual(test.c, c[i] * 2);

            }
        }


        [TestMethod]
        public void TestOperationDivide()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test /= 2;
                Assert.AreEqual(test.a, a[i] / 2);
                Assert.AreEqual(test.b, b[i] / 2);
                Assert.AreEqual(test.c, c[i] / 2);


            }
        }


        [TestMethod]
        public void TestOperationIncrement()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test++;
                Assert.AreEqual(test.a, ++a[i]);
                Assert.AreEqual(test.b, ++b[i]);
                Assert.AreEqual(test.c, ++c[i]);
            }
        }

        [TestMethod]
        public void TestOperationDecrement()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                test--;
                Assert.AreEqual(a[i] - 1, test[0]);
                Assert.AreEqual(b[i] - 1, test[1]);
                Assert.AreEqual(c[i] - 1, test[2]);
            }
        }

        [TestMethod]
        public void TestPerimeter()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                Assert.AreEqual(test.Perimeter(), a[i] + b[i] + c[i]);

            }
        }


        [TestMethod]
        public void TestArea()
        {
            double[] a = { 1.94, 2.94, 3.94 };
            double[] b = { 5.84, 6.84, 7.84 };
            double[] c = { 5.54, 6.54, 7.54 };
            for (int i = 0; i < 3; i++)
            {
                Triangle test = new Triangle(a[i], b[i], c[i]);
                double p = (a[i] + b[i] + c[i]) / 2;
                var area = Math.Sqrt(p*(p - a[i])*(p - b[i])*(p - c[i]));
                Assert.AreEqual(test.Area(), area);
            }
        }
    }
}