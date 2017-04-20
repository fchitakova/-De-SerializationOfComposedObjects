#include "Egg.h"


Egg::Egg() :name(NULL), size(0){}


void Egg::setName(const char*n)
{
	setNewValue(name, n,strlen(n)+1);
}

void Egg::setSize(const size_t s)
{
	size = s;
}

Egg::Egg(const char*n, size_t s):name(NULL)
{
	setNewValue(name, n,strlen(n)+1);
	setSize(s);
}


Egg::Egg(const Egg&rhs) :name(NULL)
{
	setNewValue(name, rhs.name,strlen(rhs.name)+1);
	setSize(rhs.size);
}


Egg& Egg::operator=(const Egg&rhs)
{
	if (this != &rhs)
	{
		setNewValue(name, rhs.name,strlen(rhs.name)+1);
		setSize(rhs.size);

	}
	return*this;
}


Egg::~Egg()
{
	delete[]name;
}


void Egg::eggSerialize(const char*filename,std::ofstream&of)   
{
	size_t n = strlen(name);
	if (of.good())
	{
		of.write((char*)&n, sizeof(int));
		of.write(name, n + 1);
		of.write((char*)&size, sizeof(size_t));
	}
}

void Egg::eggDeserialize(const char*filename, std::ifstream&i)
{
	size_t n;
	if (i.good())
	{
		i.read((char*)&n, sizeof(size_t));
		if (name)
		{
			delete[]name;
			name = new char[n + 1];
		}
		i.read(name, n + 1);
		i.read((char*)&size, sizeof(size_t));
	}
}


