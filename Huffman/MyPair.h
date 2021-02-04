#include<vector>
#include<iostream>
#include<array>
#include<string>
#include <unordered_map>

template <typename T, typename Z>
class MyPair
{
public:
	T key;
	Z value;
	MyPair(std::pair<T, Z> oldPair) : key(oldPair.first), value(oldPair.second)
	{

	}

	MyPair(T key, Z value) : key(key), value(value)
	{

	}

	bool operator <(const MyPair<T, Z>& targetPair)
	{
		return value < targetPair.value;
	}


	bool operator >(const MyPair<T, Z>& targetPair)
	{
		return value > targetPair.value;
	}
};

