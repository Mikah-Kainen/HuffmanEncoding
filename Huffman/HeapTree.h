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
		//vector.push_back(HeapNode(newValue));
		vector.emplace_back(newValue);
		int newIndex = vector.size() - 1;
		HeapifyUp(newIndex);
		count++;
	}

	void HeapifyUp(int index)
	{
		while (index != 0)
		{
			if (vector[index].value < vector[Parent(index)].value)
			{
				//Switch(index, Parent(index));
				std::swap(vector[index], vector[Parent(index)]);
				index = Parent(index);
			}
			else
			{
				break;
			}
		}
	}

	T Pop()
	{
		T returnValue = vector[0].value;
		vector[0] = vector[vector.size() - 1];

		vector.pop_back();
		/*vector.erase(vector.begin() + vector.size() - 1);*/
		HeapifyDown(0);
		count--;
		return returnValue;
	}

	void HeapifyDown(int index)
	{
		//int left_child = index * 2 + 1;

		//if (left_child >= vector.size()) return;

		//int potential_index = left_child;

		//int right_child = index * 2 + 2;

		//if (right_child < vector.size() && vector[right_child].value > vector[left_child].value)
		//{
		//	potential_index = right_child;
		//}

		//if (vector[index].value < vector[potential_index].value)
		//{
		//	std::swap(vector[index], vector[potential_index]);

		//	HeapifyDown(potential_index);
		//}


		while (LeftChild(index) < vector.size())
		{
			bool isLeftSmaller = true;
			if (RightChild(index) < vector.size())
			{
				isLeftSmaller = vector[LeftChild(index)].value < vector[RightChild(index)].value;
			}
			if (isLeftSmaller)
			{
				if (vector[index].value > vector[LeftChild(index)].value)
				{
					Switch(index, LeftChild(index));
					index = LeftChild(index);
				}
				else
				{
					break;
				}
			}
			else
			{
				if (vector[index].value > vector[RightChild(index)].value)
				{
					Switch(index, RightChild(index));
					index = RightChild(index);
				}
				else
				{
					break;
				}
			}
		}
	}


};

