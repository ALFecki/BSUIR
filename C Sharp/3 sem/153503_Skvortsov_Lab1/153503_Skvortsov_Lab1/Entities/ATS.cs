using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab1.Collections;

namespace _153503_Skvortsov_Lab1.Entities
{
    public class ATS {
        public DoublyLinked<Client> clients;
        public DoublyLinked<Tariff> tariffes;
        
        public ATS(DoublyLinked<Client> clients, DoublyLinked<Tariff> tariffes) {
            this.clients = clients;
            this.tariffes = tariffes;
        }
        public double Cost() {
            double sum = 0;
            for (int i = 0; i < clients.Count; i++) {
                sum += clients[i].NeddedMoney();
            }
            return sum;
        }
    }
}
