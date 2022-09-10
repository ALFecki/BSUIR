using Microsoft.VisualStudio.TestTools.UnitTesting;
using Classes;


namespace FlowerTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void RoseColor()
        {
            Rose test = new Rose("Rose", "Holland", 2, "Red");
            string[] colors = { "Red", "Yellow", "Pink", "Violet", "Blue" };
            for (int i = 0; i < 5; i++)
            {
                test.Color = colors[i];
                Assert.AreEqual(colors[i], test.Color);
            }
        }

        [TestMethod]
        public void ChamomileSeeds()
        {
            int[] seeds = { 44, 234, 87654, 76, 345 };
            Chamomile test = new Chamomile("Chamomile", "Russia", 3, 25);
            string warning = "There are no this count of seeds.";
            for (int i = 0; i < 5; i++)
            {
                Assert.AreEqual(warning, test.Seeds(seeds[i]));
            }
        }

        [TestMethod]
        public void ChamomileNation()
        {
            string[] nations = { "Holland", "Russia", "Belarus", "Italy", "China" };
            Chamomile test = new Chamomile("Chamomile", "Russia", 3, 25);
            for (int i = 0; i < 5; i++)
            {
                test.Nation = nations[i];
                Assert.AreEqual(nations[i], test.Nation);
            }
        }

    }
}