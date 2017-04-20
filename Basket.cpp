#include "Basket.h"


Basket::Basket() :ownerName(NULL), eggs(NULL), size(0) {}

void Basket::setName(const char*str)
{
	setNewValue(ownerName, str,strlen(str)+1);
}

void Basket::setSize(const size_t s)
{
	size = s;
}


void Basket::setEggs(const Egg*eggs)
{
	setNewValue(this->eggs, eggs, size/2);
}

Basket::Basket(const Basket&rhs) :ownerName(NULL), eggs(NULL), size(0) 
{
	setNewValue(ownerName, rhs.ownerName,strlen(rhs.ownerName)+1);
	setNewValue(eggs, rhs.eggs, sizeof(rhs.eggs));
	size = rhs.size;
}


Basket&Basket::operator=(const Basket&rhs)
{
	if (this != &rhs)
	{
		setNewValue(ownerName, rhs.ownerName, strlen(rhs.ownerName) + 1);
		setNewValue(eggs, rhs.eggs, sizeof(rhs.eggs));
		size = rhs.size;
	}
	return *this;
}



void Basket::addEgg(const char*str)
{
	Egg*buffer=new Egg[size];
	setNewValue(buffer, eggs, size);
	size += 2;  
	delete[]eggs;
	eggs = new Egg[size];
	setNewValue(eggs, buffer, size - 2);
	delete[]buffer;
	Egg*helper = new Egg(str, 1);
	eggs[size - 1] = *helper;
	delete[]helper;
}


void Basket::removeEgg(const char*str)
{
	bool flag = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (strcmp(eggs[i].getName(), str) == 0)
		{
			flag = true;
			std::swap(eggs[i], eggs[size / 2]);
			eggs[size / 2].setName("Unvalid!\n");
			eggs[size / 2].setSize(-1);
			size = size - 2;
		}
	}
}


void Basket::Serialize(const char*filename)const
{
	size_t namelen = strlen(ownerName);
	std::ofstream of(filename,std::ios::binary | std::ios::out);
	of.write((char*)&ownerName, sizeof(size_t));
	of.write(ownerName, namelen + 1);
	of.write((char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size / 2; ++i)
	{
		eggs[i].eggSerialize(filename, of);
	}
	of.close();
}


void Basket::Deserialize(const char*filename)
{
	    size_t namelen;
		std::ifstream i(filename, std::ios::binary | std::ios::in);
		i.read((char*)&namelen, sizeof(size_t));
		if (ownerName)
		{
			delete[]ownerName;
			ownerName = new char[namelen + 1];
		}
		i.read(ownerName, namelen + 1);
		i.read((char*)&size, sizeof(size_t));
		for (size_t j = 0; j < size / 2; ++j)
		{
			eggs[j].eggDeserialize(filename, i);
		}
	     i.close();
}


void Basket::Report()const
{
	char*filename = new char[MAX_SIZE];
	strcpy(filename, "report_");
	strcat(filename, ownerName);
	strcat(filename, ".txt");
	std::ofstream report(filename, std::ios::out);
	if (report)
	{
		report << "Name of the egg basket: " << ownerName << '\n'
			<< "Containing :\n";
		for (size_t i = 0; i < size / 2; ++i)
		{
			report << "EggNo " << i << ": Name :" << eggs[i].getName() << " and Size: " << eggs[i].getSize() << '\n';
		}
	}

		delete[]filename;
}


Basket::~Basket()
{
	delete[]ownerName;
	delete[]eggs;
}