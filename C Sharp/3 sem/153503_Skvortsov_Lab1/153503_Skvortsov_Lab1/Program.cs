using _153503_Skvortsov_Lab1.Collections;
using _153503_Skvortsov_Lab1.Entities;



void PrintClients(DoublyLinked<Client> clients) {
    Console.WriteLine("********СПИСОК КЛИЕНТОВ*********");
    for (int i = 0; i < clients.Count; i++) {
        
        Console.WriteLine("Имя: " + clients[i].Name + " Количество звонков: " + clients[i].CallsNumber.ToString());
    }
    Console.WriteLine("********СПИСОК КЛИЕНТОВ*********");
}

void PrintTariffes(DoublyLinked<Tariff> tariffes) {
    Console.WriteLine("********СПИСОК ТАРИФОВ*********");
    for (int i = 0; i < tariffes.Count; i++) {
        Console.WriteLine("Имя: " + tariffes[i].Name + " Стоимость: " + tariffes[i].Cost.ToString());
    }
    Console.WriteLine("********СПИСОК ТАРИФОВ*********");
}

void AddClient(DoublyLinked<Client> clients, DoublyLinked<Tariff> tariffes) {
    Console.WriteLine("Введите имя клиента");
    string name = Console.ReadLine();
    PrintTariffes(tariffes);
    Console.WriteLine("Введите тариф");
    string tariffName = Console.ReadLine().ToString();
    for (int k = 0; k < tariffes.Count; k++) {
        if (tariffes[k].Name == tariffName) {
            clients.Add(new Client(name, tariffes[k]));
            Console.WriteLine("*УСПЕШНО*\n\n");
            break;
        }
    }
    if (tariffes == null) {
        Console.WriteLine("Такого тарифа не существует");
        return;
    }
}


bool t = true;
Console.WriteLine("Здравствуйте!");
Console.Write("Пожалуйста, введите количество тарифов: ");
int tariffCount = Convert.ToInt32(Console.ReadLine());
DoublyLinked<Tariff> tariff = new DoublyLinked<Tariff>();
for (int i = 0; i < tariffCount; i++) {
    Console.WriteLine("Введите название тарифа: ");
    string name = Console.ReadLine().ToString();
    Console.WriteLine("Введите цену тарифа: ");
    int cost = Convert.ToInt32(Console.ReadLine());
    tariff.Add(new Tariff(name, cost));
    Console.WriteLine("*УСПЕШНО*\n\n");
}
Console.Write("Пожалуйста, введите количество клиентов: ");
int clientCount = Convert.ToInt32(Console.ReadLine());
DoublyLinked<Client> clients = new DoublyLinked<Client>();
for (int i = 0; i < clientCount; i++) {
    Console.WriteLine("Введите имя клиента: ");
    string name = Console.ReadLine().ToString();
    PrintTariffes(tariff);
    Console.WriteLine("Выберите тариф клиента: ");
    string tariffName = Console.ReadLine().ToString();
    for (int k = 0; k < tariff.Count; k++) {
        if (tariff[k].Name == tariffName) {
            clients.Add(new Client(name, tariff[k]));
            Console.WriteLine("*УСПЕШНО*\n\n");
            break;
        }
    }
}

ATS ats = new ATS(clients, tariff);
while (t) {
    Console.WriteLine("================================================");
    Console.WriteLine("1 - Посмотреть список клиентов");
    Console.WriteLine("2 - Посмотреть список тарифов");
    Console.WriteLine("3 - Регистрировать звонок");
    Console.WriteLine("4 - Вывести задолженность клиента");
    Console.WriteLine("5 - Вывести задолженность всех клиентов");
    Console.WriteLine("6 - Добавить клиента");
    Console.WriteLine("7 - Выход");
    Console.WriteLine("================================================");
    Console.Write("Введите номер команды: ");
    int command = Convert.ToInt32(Console.ReadLine());
    switch (command) {
        case 1:
            PrintClients(clients);
            break;
        case 2:
            PrintTariffes(tariff);
            break;
        case 3: {
                PrintClients(clients);
                Console.WriteLine("Введите имя клиента: ");
                string name = Console.ReadLine().ToString();
                for (int i = 0; i < clients.Count; i++) {
                    if (clients[i].Name == name) {
                        Console.WriteLine("Введите количество минут: ");
                        double minutes = Convert.ToDouble(Console.ReadLine());
                        clients[i].RegisterCall(minutes);
                        Console.WriteLine("*УСПЕШНО*\n\n");
                        break;
                    }
                }
                break;
            }
        case 4: {
                PrintClients(clients);
                Console.WriteLine("Введите имя клиента: ");
                string name = Console.ReadLine().ToString();
                for (int i = 0; i < clients.Count; i++) {
                    if (clients[i].Name == name) {
                        Console.WriteLine("Задолженность клиента: " + clients[i].NeddedMoney().ToString());
                        break;
                    }
                }
                break;
            }
        case 5: {
                Console.WriteLine("Задолженность всех клиентов: " + ats.Cost().ToString());
                break;
            }
        case 6: {
                AddClient(clients, tariff);
                break;
            }
        case 7: {
                t = false;
                break;
            }




    }
}