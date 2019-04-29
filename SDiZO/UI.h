#include <time.h>
#include <cstring>
#include "My_Environment.h"
#include "MyArrayList.h"
#include "MyArrayListSlow.h"
#include "MyHeap.h"
#include "MyLinkedList.h"
#include "MyRedBlackTree.h"



class UI
{
public:
	UI();
	void mainLoop();
	void testCompare();
	/*void benchmark();
	void tests();
	void testArrayListSlow();
	void testArrayList();
	void testLinkedList();
	void testHeap();
	void testRedBleackTree();
	void printToFile(const std::vector<int>&, std::string);
	std::vector<int>* readFromFile(const std::string&);*/
	void timerStart();
	void timerStop();
	std::vector<int>* generateRandom(const int&);
	std::vector<int>* generateOrder(const int&);

	void pushBack(int);
	void pushFront(int);
	void popBack();
	void popFront();
	void add(std::string);
	void del(int);
	void getIndex(int);
	void get(int);

	////ArrayListSlow
	//void pushBack(MyArrayListSlow&, int);
	//void pushFront(MyArrayListSlow&, int);
	//void popFront(MyArrayListSlow&, int);
	//void popBack(MyArrayListSlow&, int);
	////ArrayList
	//void pushBack(MyArrayList&, int);
	//void pushFront(MyArrayList&, int);
	//void popFront(MyArrayList&, int);
	//void popBack(MyArrayList&, int);
	////LinckedList
	//void pushBack(MyLinkedList&, int);
	//void pushFront(MyLinkedList&, int);
	//void popFront(MyLinkedList&, int);
	//void popBack(MyLinkedList&, int);
	////Heap
	//void add(MyHeap&, int);
	//void del(MyHeap&, int);
	////RedBlackTree
	//void add(MyRedBlackTree&, int);
	//void del(MyRedBlackTree&, int);

	//~UI();


private:
	MyArrayListSlow* myArrayListSlow;
	MyArrayList* myArrayList;
	MyLinkedList* myLinkedList;
	MyHeap* myHeap;
	MyRedBlackTree* myRedBlackTree;
	std::vector<int>* list;
	std::vector<std::string>* command;
	std::vector<std::string>* properties;
	std::vector<std::string>* numbers;
	int time;
};
