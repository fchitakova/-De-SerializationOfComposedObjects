#ifndef EGG_H
#define EGG_H

#include <fstream>
#include <iostream>
#include <cstring>

class Egg
{
public:
	Egg();
	Egg(const char*n, size_t s);
	Egg(const Egg&rhs);
	Egg&operator=(const Egg&rhs);
	~Egg();
	const char*getName()const { return this->name; };
	size_t getSize()const { return this->size; };
	void setName(const char*n);
	void setSize(const size_t s);
	void eggSerialize(const char*filename,std::ofstream&of);
	void eggDeserialize(const char*filename,std::ifstream&i);
private:
	char*name;
	size_t size;
};

template <typename T>
void setNewValue(T*&dest,const T*source,size_t length)
{
	if (!source)
	{
		delete[]dest;
		dest = NULL;
		return;
	}
	//size_t length = strlen(source) + 1;
	T*buffer = NULL;
	try
	{
		buffer = new T[length];
	}
	catch (std::bad_alloc&)
	{
		delete[]dest;
		throw "Bad alloc caught!\n";
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = source[i];
	}

	delete[]dest;
	dest = buffer;
}





#endif