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
	std::string last;
	while (currentNode.RightChild)
	{
		last += '1';
		returnVector.emplace(currentNode.LeftChild->value.key, returnVector[currentNode.value.key] + '0');
		returnVector[currentNode.value.key] += '1';
		currentNode = *currentNode.RightChild;
	}
	if (currentNode.LeftChild)
	{
		returnVector.emplace(currentNode.LeftChild->value.key, last + '0');
	}
	returnVector.emplace(currentNode.value.key, last + '1' + '0');
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


std::string IntToString(std::string intValues)
{
	int length = intValues.size();
	int extra = length % 8;

	std::vector<std::byte> byteValues{};
	for (int i = 0; i < length / 8; i++)
	{
		std::byte b = (std::byte)0;
		byteValues.push_back(b);

		for (int x = 0; x < 8; x++)
		{
			byteValues[i] |= (std::byte)((int)intValues[8 * i + x] - 48) << (8 - x - 1);
		}
	}

	std::string returnString;
	for (std::byte newChar : byteValues)
	{
		returnString += (char)newChar;
	}

	returnString.append(std::to_string(extra));
	std::byte lastByte;
	for (int x = 0; x < extra; x++)
	{
		lastByte |= (std::byte)((int)intValues[length - extra + x] - 48) << (8 - x - 1);
	}

	returnString += (char)lastByte;
	return returnString;
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
	std::string TestString = "This is a test message that I am making up as I type. Hopefuly, my program will work and this message will be decoded. If it doesn't that would be sad but I would make sure to promptly fix it!";
	/*for (size_t i = 0; i < 120; i ++)
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
	TestString += "ZZKKKKKKK";*/
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

	std::string compressedString;
	for (char letter : TestString)
	{
		compressedString += charToString[letter];
	}

	std::cout << IntToString(compressedString) << std::endl;

	//REad the bytes and turn back into string

	std::string tempHolder;
	std::string resultString;
	for (char letter : compressedString)
	{
		tempHolder += letter;
		if (letter == '0')
		{
			resultString += stringToChar[tempHolder];
			tempHolder = "";
		}
	}
	return 0;

}


//read all values
//use dictionary to keep track of the use of each letter
//add all the key value pairs of the dictionary to the heap
//create new dictionary that maps chars to their new binary representations, after you "walk" the tree to get the path (0 for left, 1 for right)