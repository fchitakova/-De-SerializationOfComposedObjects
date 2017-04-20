#include "Basket.h"



int main()
{

	//Serialization
	Egg egg1("egg1", 1);
    Egg egg2("egg2", 2);
	Egg eggs[2];
	eggs[0] = egg1;
	eggs[1] = egg2;
	Basket mybasket;
	mybasket.setName("Fiffy");
	mybasket.setSize(4);
	mybasket.setEggs(eggs);
	mybasket.Serialize("baskets.bin");

	//Deserialization
	Egg*egg3 = new Egg("Egg3", 0);
	Basket mybasket2;
	mybasket2.setName("Fiffy2");;
	mybasket2.setSize(2);
	mybasket2.setEggs(egg3);
	mybasket2.Deserialize("baskets.bin");
	std::cout << mybasket2.getName() << " " << mybasket2.getSize();
  
	std::cout << '\n' << mybasket2.getEggs()[0].getName() << " " << mybasket2.getEggs()[0].getSize();

	mybasket2.Report();

	delete egg3;
	return 0;
}