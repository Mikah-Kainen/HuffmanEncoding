#include<vector>
#include<iostream>
#include<array>
#include<string>
#include <unordered_map>
#include"HeapTree.h"
#include"MyPair.h"

using Node = HeapTree<MyPair<char, int>>::HeapNode;

std::vector<Node> uniqueTraversal(Node targetNode)
{
	std::vector<Node> returnVector;
	Node currentNode = targetNode;
	while (currentNode.RightChild)
	{
		returnVector.push_back(*currentNode.LeftChild);
		currentNode = *currentNode.RightChild;
	}
	returnVector.push_back(currentNode);
	if (currentNode.LeftChild)
	{
		returnVector.push_back(*currentNode.LeftChild);
	}
	return returnVector;
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

	std::unordered_map<char, int> charToInt{};
	std::unordered_map<int, char> intToChar{};

	std::vector<Node> resultNode = uniqueTraversal(newTree);
	std::vector<std::string> resultInt{};
	resultInt.push_back("0");
	for (int i = 1; i < resultNode.size(); i++)
	{
		if (resultInt[i - 1][resultInt[i-1].size() - 1] == '0')
		{
			resultInt.push_back(resultInt[i-1] + '1');
		}
		else
		{
			resultInt.push_back(resultInt[i - 1] + '0');
		}
	}

	return 0;
}


//read all values
//use dictionary to keep track of the use of each letter
//add all the key value pairs of the dictionary to the heap
//create new dictionary that maps chars to their new binary representations, after you "walk" the tree to get the path (0 for left, 1 for right)