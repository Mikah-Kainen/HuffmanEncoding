#pragma once
#include<vector>
#include<iostream>
#include<array>
#include<string>


template <typename T>
class HeapTree
{
private:

	struct HeapNode
	{
		T value;
		char letter;
		std::shared_ptr<HeapNode> LeftChild;
		std::shared_ptr<HeapNode> RightChild;
		
		bool isLeaf()
		{
			return !LeftChild && !RightChild;
		}

		HeapNode(T value) : value(value)
		{
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};

	int Parent(int index)
	{
		return (index - 1 )/ 2;
	}
	
	int LeftChild(int index)
	{
		return index * 2 + 1;
	}

	int RightChild(int index)
	{
		return index * 2 + 2;
	}

	bool Switch(int firstIndex, int secondIndex)
	{
		if (firstIndex >= vector.size() || secondIndex >= vector.size())
		{
			return false;
		}
		HeapNode temp = vector[firstIndex];
		vector[firstIndex] = vector[secondIndex];
		vector[secondIndex] = temp;
		return true;
	}

	std::vector<HeapNode> vector{};

public:
	int count = {};

	void Insert(T newValue)
	{
		vector.push_back(HeapNode(newValue));
		int newIndex = vector.size() - 1;
		HeapifyUp(newIndex);
	}

	void HeapifyUp(int index)
	{
		while (index != 0)
		{
			if (vector[index] > vector[Parent(index)])
			{
				Switch(index, Parent(index));
			}
			else
			{
				break;
			}
		}
	}

	T Pop()
	{
		T returnValue = vector[0];
		vector[0] = vector[vector.size() - 1];
		vector[vector.size() - 1] = null;
		HeapifyDown(0);
		return returnValue;
	}

	void HeapifyDown(int index)
	{
		while (LeftChild(index) < vector.size())
		{
			bool isLeftBigger = LeftChild(index) > RightChild(index);
			if (isLeftBigger)
			{
				if (vector[index] < vector[LeftChild(vector)])
				{

				}
			}
			else
			{

			}
		}
	}


};

