using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    internal class Сhamomile : Flower
    {
        private string field;


        public Chamomile(string name)
                : base(name)
        {
            Flower.GrowthField("");
        }

    }
}
