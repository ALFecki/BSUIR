#include "weak_ptr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"

class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
	// Выделяем Item и передаем его в std::shared_ptr
	auto ptr1 = make_shared_ptr<Item>();
	{
		auto ptr2 = ptr1; // создаем ptr2 из ptr1, используя семантику копирования

		std::cout << "Killing one shared pointer\n";
	} // ptr2 выходит из области видимости здесь, но ничего больше не происходит

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 выходит из области видимости здесь, и выделенный Item также уничтожается здесь














//class Item
//{
//public:
//	Item() { std::cout << "Item acquired\n"; }
//	~Item() { std::cout << "Item destroyed\n"; }
//
//	friend std::ostream& operator<<(std::ostream& out, const Item& item)
//	{
//		out << "I am an Item!\n";
//		return out;
//	}
//};
//
//// Эта функция использует только Item, поэтому мы передаем указатель на Item, а не ссылку на весь std::unique_ptr<Item>
//void useItem(Item* item)
//{
//	if (item)
//		std::cout << *item;
//}
//
//int main()
//{
//	
//	auto ptr = make_unique_ptr<Item>();
//
//	useItem(ptr.get()); // примечание: Метод get() используется для получения указиателя на Item
//
//	std::cout << "Ending program\n";
//
//	return 0;
//} // Item уничтожается здесь
//
















//class Human
//{
//	std::string m_name;
//	My_weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr
//
//public:
//
//	Human(const std::string& name) : m_name(name)
//	{
//		std::cout << m_name << " created\n";
//	}
//	~Human()
//	{
//		std::cout << m_name << " destroyed\n";
//	}
//
//	friend bool partnerUp(My_shared_ptr<Human>& h1, My_shared_ptr<Human>& h2)
//	{
//		if (!h1 || !h2)
//			return false;
//
//		h1->m_partner = h2;
//		h2->m_partner = h1;
//
//		std::cout << h1->m_name << " is now partnered with " << h2->m_name << "\n";
//
//		return true;
//	}
//
//	const My_shared_ptr<Human> getPartner() const { return m_partner.lock(); } // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
//	const std::string& getName() const { return m_name; }
//};
//
//int main()
//{
//	
//	auto anton = make_shared_ptr<Human>("Anton");
//	auto ivan = make_shared_ptr<Human>("Ivan");
//
//	partnerUp(anton, ivan);
//
//	auto partner = ivan->getPartner(); // передаем partner-у содержимое умного указателя, которым владеет ivan
//	std::cout << ivan->getName() << "'s partner is: " << partner->getName() << '\n';
//
//	return 0;
//}
