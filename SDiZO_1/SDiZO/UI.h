#include <time.h>
#include <cstring>
#include <fstream>
#include "My_Environment.h"
#include "MyArrayList.h"
#include "MyArrayListSlow.h"
#include "MyHeap.h"
#include "MyLinkedList.h"
#include "MyRedBlackTree.h"
#include "TimeCheck.h"



class UI
{
public:
	UI();
	void mainLoop();
	void testCompare();
	void benchmark();
	void tests();
	void testArrayListSlow();
	void testArrayList();
	void testLinkedList();
	void testHeap();
	void testRedBleackTree();
	void printToFile(std::vector<int>*, std::string);
	std::vector<int>* readFromFile(std::string);
	void timerStart();
	void timerStopP();
	void timerStop();
	void timerStopFunc(std::string);
	void timerStartFunc();
	std::vector<int>* generateRandom(const int&);
	std::vector<int>* generateOrder(const int&);
	void deleteArray();

	void pushBack(int);
	void pushFront(int);
	void popBack();
	void popFront();
	void add(std::string);
	void del(int);
	void getIndex(int);
	void get(int);

	//ArrayListSlow
	void pushBack(MyArrayListSlow*);
	void pushFront(MyArrayListSlow*);
	void popFront(MyArrayListSlow*);
	void popBack(MyArrayListSlow*);
	void add(MyArrayListSlow*);
	void del(MyArrayListSlow*);
	void iteration(MyArrayListSlow*);
	//ArrayList
	void pushBack(MyArrayList*);
	void pushFront(MyArrayList*);
	void popFront(MyArrayList*);
	void popBack(MyArrayList*);
	void add(MyArrayList*);
	void del(MyArrayList*);
	void iteration(MyArrayList*);
	//LinckedList
	void pushBack(MyLinkedList*);
	void pushFront(MyLinkedList*);
	void popFront(MyLinkedList*);
	void popBack(MyLinkedList*);
	void add(MyLinkedList*);
	void del(MyLinkedList*);
	void iteration(MyLinkedList*);
	//Heap
	void add(MyHeap*);
	void del(MyHeap*);
	void iteration(MyHeap*);
	//RedBlackTree
	void add(MyRedBlackTree*);
	void del(MyRedBlackTree*);
	void iteration(MyRedBlackTree*);

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
	TimeCheck time;
	TimeCheck timeFunc;
};
