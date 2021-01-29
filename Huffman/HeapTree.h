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

		HeapNode(T value, char letter) : value(value), letter(letter)
		{
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};

public:
	int count = {};


	HeapTree()
	{
		
	}
};

