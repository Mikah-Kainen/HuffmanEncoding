#include<vector>
#include<iostream>
#include<array>
#include<string>
#include <unordered_map>
#include"HeapTree.h"
#include"MyPair.h"

using Node = HeapTree<MyPair<char, int>>::HeapNode;

std::unordered_map<char, std::string> uniqueTraversal(Node targetNode)
{
	std::unordered_map<char, std::string> returnVector;
	Node currentNode = targetNode;
	while (currentNode.RightChild)
	{
		returnVector.emplace(currentNode.LeftChild->value.key, returnVector[currentNode.value.key] + '0');
		returnVector[currentNode.value.key] += '1';
		currentNode = *currentNode.RightChild;
	}
	if (currentNode.LeftChild)
	{
		returnVector.emplace(currentNode.LeftChild->value.key, returnVector[currentNode.value.key] + '0');
	}
	return returnVector;
}

 template<typename T, typename Z>
std::unordered_map<Z, T> invertDictionary(std::unordered_map<T, Z> targetMap)
{
	std::unordered_map<Z, T> returnMap{};
	for (std::pair<T, Z> pair : targetMap)
	{
		returnMap.emplace(pair.second, pair.first);
	}
	return returnMap;
}
int main()
{



	/*HeapTree<int> tree{};*/
	//tree.Insert(20);
	//tree.Insert(1);
	//tree.Insert(0);
	//tree.Insert(5);
	//tree.Insert(10);
	//tree.Insert(6);

	///*int returnval = tree.Pop();
	//int returnval2 = tree.Pop();*/


	std::unordered_map<char, int> dictionary{};
	//char letter = 'a';
	//for (size_t i = 0; i < 10; i++)
	//{
	//	dict[i] = letter++;
	//}

	//for (auto mypair : dict)
	//{
	//	std::cout << mypair.first << " = " << mypair.second << std::endl;
	//}

	/*std::string TestString = "This is the test ittsss";*/
	std::string TestString;
	for (size_t i = 0; i < 120; i ++)
	{

		TestString += 'E';
	}
	for (size_t i = 0; i < 37; i++)
	{

		TestString += 'U';
	}
	for (size_t i = 0; i < 42; i++)
	{

		TestString += 'D';
		TestString += 'L';
	}
	for (size_t i = 0; i < 32; i++)
	{

		TestString += 'C';
	}
	for (size_t i = 0; i < 24; i++)
	{

		TestString += 'M';
	}
	TestString += "ZZKKKKKKK";
	for (char letter : TestString)
	{
		dictionary[letter] ++;
	}
	//st ie/hT
	
	HeapTree<MyPair<char, int>> tree{};
	for (std::pair<char, int> pair : dictionary)
	{
		tree.Insert(MyPair<char, int>(pair));
	}


	HeapTree<MyPair<char, int>>::HeapNode newTree = tree.BuildTree();

	std::unordered_map<char, std::string> charToString = uniqueTraversal(newTree);
	std::unordered_map<std::string, char> stringToChar = invertDictionary<char, std::string>(charToString);

	return 0;
}


//read all values
//use dictionary to keep track of the use of each letter
//add all the key value pairs of the dictionary to the heap
//create new dictionary that maps chars to their new binary representations, after you "walk" the tree to get the path (0 for left, 1 for right)