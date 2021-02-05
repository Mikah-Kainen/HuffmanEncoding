#include<vector>
#include<iostream>
#include<array>
#include<string>
#include <unordered_map>
#include"HeapTree.h"
#include"MyPair.h"



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

	std::string TestString = "This is the test ittsss";
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

	MyPair<char, int> pair1 = tree.Pop();
	MyPair<char, int> pair2 = tree.Pop();
	MyPair<char, int> pair3 {'\0', pair1.value + pair2.value};
	MyPair<char, int> pair4 = tree.Pop();
	MyPair<char, int> pair5 {'\0', pair3.value + pair4.value};

	tree.BuildTree();
	return 0;
}


//read all values
//use dictionary to keep track of the use of each letter
//add all the key value pairs of the dictionary to the heap
//create new dictionary that maps chars to their new binary representations, after you "walk" the tree to get the path (0 for left, 1 for right)