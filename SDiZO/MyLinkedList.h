#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class MyLinkedList
{
public:

	MyLinkedList();
	void pushFront(int val);
	void pushBack(int val);
	void addIn(int number, int val);
	int getIndex(int val);
	Node* get(int index);
	int getLength();
	Node* popBack();
	Node* popFront();
	Node* del(int index);
	static void printToConsole(MyLinkedList *tmp);

	~MyLinkedList();

private:
	Node* head;
	Node* tail;
	int length;
};