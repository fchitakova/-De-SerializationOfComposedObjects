#ifndef BASKET_H
#define BASKET_H

#include "Egg.h"
#include <iostream>

const int MAX_SIZE = 500;

class Basket
{
public:
	Basket();
	Basket(const Basket&rhs);
	Basket&operator=(const Basket&rhs);
	~Basket();
	char*getName()const { return ownerName; }
	size_t getSize()const { return size; }
	Egg* getEggs()const { return eggs; }
	void setName(const char*str);
	void setSize(const size_t s);
	void setEggs(const Egg*eggs);
	void removeEgg(const char*str);
	void addEgg(const char*str);
	void Serialize(const char*filename)const;
	void Deserialize(const char*filename);
	void Report()const;
private:
	char*ownerName;
	size_t size;
	Egg*eggs;
};


#endif