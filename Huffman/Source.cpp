#include<vector>
#include<iostream>
#include<array>
#include<string>
#include <unordered_map>
#include"HeapTree.h"

int main()
{

	//HeapTree<(int count, char letter)> tree{};
	//tree.Insert((0, 'A'));
	//tree.Insert((5, 'B'));
	//tree.Insert((10, 'C'));
	//tree.Insert((6, 'D'));

	///*int returnval = tree.Pop();
	//int returnval2 = tree.Pop();*/


	//while (tree.count != 0)
	//{
	//	std::cout << tree.Pop() << std::endl;
	//}

	/*std::unordered_map<int, int> dict{};

	if (dict.find(5) != dict.end())
	{
		std::cout << "found 5" << std::endl;
	}
	else
	{
		std::cout << "did not find 5" << std::endl;
	}*/

	//std::pair<int, int> kvp{ 5, 4 };

	std::unordered_map<int, char> dict{};

	char letter = 'a';
	for (size_t i = 0; i < 10; i++)
	{
		dict[i] = letter++;
	}

	for (auto mypair : dict)
	{
		std::cout << mypair.first << " = " << mypair.second << std::endl;
	}


	return 0;
}


//read all values
//use dictionary to keep track of the use of each letter
//add all the key value pairs of the dictionary to the heap
//create new dictionary that maps chars to their new binary representations, after you "walk" the tree to get the path (0 for left, 1 for right)