#include <iostream>


class MyArrayListSlow
{
public:
	MyArrayListSlow();

	void pushBack(int val);
	void pushFront(int val);
	void addIn(int number, int val);
	int getIndex(int val);
	int popBack();
	int popFront();
	int del(int index);

	~MyArrayListSlow();

private:
	int size;
	int *array;
};
