#include <iostream>

class MyArrayList
{
public:
	MyArrayList();

	void pushBack(int val);
	void pushFront(int val);
	void addIn(int number, int val);
	int getIndex(int val);
	int popBack();
	int popFront();
	int del(int index);
	static void printToConsole(MyArrayList* tmp);

	~MyArrayList();

private:
	int size;
	int lenght;
	int* array;
};
