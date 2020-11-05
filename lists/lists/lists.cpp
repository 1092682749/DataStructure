// lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LinkedNode.h"
#include <Windows.h>
#include <vector>
#include <algorithm>
template<typename T> void  each(T item, int index) {
	std::cout << item << std::endl;
	// std::cout << index << std::endl;
}

 int map(char item, int index) 
 {
	// std::cout << item << std::endl;
	if (item == 'A')
		return 1;
	if (item == 'B')
		return 2;
	if (item == 'C')
		return 3;
	if (item == 'D')
		return 4;
	if (item == 'E')
		return 5;
	if (item == 'F')
		return 6;
	return 0;
	// std::cout << index << std::endl;
}
 using namespace std;






int main()
{


	LinkedNode<char> *node1 = new LinkedNode<char>('A');
	int sizeofNodePtr = sizeof(node1);
	int sizeofNode = sizeof(*node1);
	std::cout << sizeofNodePtr << std::endl;
	std::cout << sizeofNode << std::endl;
	LinkedNode<char> *node2 = new LinkedNode<char>('B');
	LinkedNode<char> *node3 = new LinkedNode<char>('C');
	LinkedNode<char> *node4 = new LinkedNode<char>('D');
	LinkedNode<char> *node5 = new LinkedNode<char>('E');
	LinkedNode<char> *node6 = new LinkedNode<char>('F');
	LinkedList<char> list(new LinkedNode<char>('#'));
	list.add(node1);
	list.add(node2);
	list.add(node3);
	list.add(node4);
	list.add(node5);
	list.add(node6);
	auto fun = [](char item, int index) -> int {return 0; };
	 LinkedList<int> iList = list.map(map);
	 iList.foreach(each);


	
	
}