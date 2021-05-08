#include <iostream>
#include <fstream>

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
	int get(int index);
	static void printToConsole(MyArrayList* tmp);
	int getLength();
	int getSize();
	static void printToFile(MyArrayList* tmp, std::string);

	~MyArrayList();

private:
	int size;
	int length;
	int* array;
};
