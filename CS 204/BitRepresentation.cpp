#include<iostream>
#include<sstream>
#include <string>
#include <vector>
#include "BitRepresentation.h"

using namespace std;

template <typename T>
BitRepresentation<T>::BitRepresentation(T number)
{
	data = number;
}

template <typename T>
BitRepresentation<T>::BitRepresentation(vector<bool> vec)
{
	data = 0; // initialize data to 0
	int bits = sizeof(T) * 8;

	int n = min(vec.size(), (size_t)bits); // number of bits to set
	for (int i = 0; i < n; i++) {
		if (vec[vec.size() - 1 - i]) {
			// set the i-th bit of data to 1
			data |= (1 << i);
		}
	}

}





template<typename T>
string BitRepresentation<T>::getBinary() 
{
	string binary;

	for (size_t i = 0; i < sizeof(T) * 8; ++i) {
		binary += ((data >> (sizeof(T) * 8 - 1 - i)) & 1) ? '1' : '0';
	}

	return binary;
}

template<typename T>
string BitRepresentation<T>::getHexadecimal() 
{
	stringstream stream;
	stream << hex << data;
	string result = stream.str();
	
	while (result.length() < sizeof(T) * 2)
		result = "0" + result;

	return result;
}

template<typename T>
void BitRepresentation<T>::setBit(unsigned int location)
{
	if (location < (sizeof(T) * 8)) {
		unsigned int val = 1 << location;

		data |= val;
	}
}

template<typename T>
void BitRepresentation<T>::unsetBit(unsigned int location)
{
	if (location < (sizeof(T) * 8)) {
		unsigned int val = ~(1 << location);

		data &= val;
	}
}

template<typename T>
bool BitRepresentation<T>::isBitSet(unsigned int location) {
	unsigned int val = 1 << location;

	return (data & val) != 0;

}

template<typename T>
T BitRepresentation<T>::getNumber() {

	return data;
}
