#include<iostream>
#include <string>
#include <vector>
#ifndef _HEADERGUARD_H
#define _HEADERGUARD_H
using namespace std;

template <typename T>
class BitRepresentation
{
private:
	T data;

public:
	BitRepresentation(T number);
	BitRepresentation(vector<bool> v1);

	string getHexadecimal();
	string getBinary();

	void setBit(unsigned int location);
	void unsetBit(unsigned int location);
	bool isBitSet(unsigned int location);

	T getNumber();

};
#include "BitRepresentation.cpp"	
#endif