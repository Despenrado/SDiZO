#include <iostream>
#include <fstream>

class MyHeap
{
public:
	MyHeap();
	void add(int);
	int getIndex(int);
	int get(int);
	int getSize();
	int getLength();
	static void printToConsole(MyHeap*);
	static void printToFile(MyHeap* tmp, std::string);
	void del(int);
	

	~MyHeap();

private:
	int* array;
	int size;
	int length;

	void correctionDown(int);
	void correctHeap();
	void correctionAdd();
};
