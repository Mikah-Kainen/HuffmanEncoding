#pragma once
#include<vector>
#include<iostream>
#include<array>
#include<string>
#include"HeapTree.h"

int Main()
{

	HeapTree<int> tree = HeapTree<int>();
	tree.Insert(0);
	tree.Insert(5);
	tree.Insert(10);
	tree.Insert(6);

	return 0;
}