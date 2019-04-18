#include "pch.h"
#include "MyLinkedList.h"

MyLinkedList::MyLinkedList()
{
	length = 0;
	tail = NULL;
	head = NULL;
}

void MyLinkedList::pushFront(int val)
{
	Node* tmp = new Node;
	tmp->data = val;
	tmp->prev = NULL;
	if (head == NULL)
	{
		tmp->next = NULL;
		head = tmp;
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
	}
	length++;
}

void MyLinkedList::pushBack(int val)
{
	Node* tmp = new Node;
	tmp->data = val;
	tmp->next = NULL;
	if (head == NULL)
	{
		tmp->prev = NULL;
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
	length++;
}

void MyLinkedList::addIn(int index, int val)
{
	if (index > length || index < 0) { return; }
	if (index == 0) { pushFront(val); return; }
	if (index == length) { pushBack(val); return; }

	Node* tmp;
	if (index < length / 2)
	{
		tmp = head;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (int i = length - 1; i > index; i--)
		{
			tmp = tmp->prev;
		}
	}
	Node* newNode = new Node;
	newNode->data = val;
	newNode->prev = tmp->prev;
	newNode->next = tmp;
	tmp->prev->next = newNode;
	tmp->prev = newNode;
	length++;
}

int MyLinkedList::getIndex(int val)
{
	int i = 0;
	Node* tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == val)
		{
			return i;
		}
		tmp = tmp->next;
		i++;
	}
	return -1;
}

Node* MyLinkedList::get(int index)
{
	if (index >= length || index < 0) { return NULL; }

	Node* tmp;
	if (index < length / 2)
	{
		tmp = head;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (int i = length - 1; i > index; i--)
		{
			tmp = tmp->prev;
		}
	}
	return tmp;
}

int MyLinkedList::getLength()
{
	return length;
}

Node* MyLinkedList::popBack()
{
	if (head == NULL || tail == NULL) { return NULL; }

	Node* tmp = tail;
	if (tail->prev == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	length--;
	return tmp;
}

Node* MyLinkedList::popFront()
{
	if (head == NULL || tail == NULL) { return NULL; }

	Node* tmp = head;
	if (head->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
	}
	length--;
	return tmp;
}

Node* MyLinkedList::del(int index)
{
	if (head == NULL || tail == NULL) { return NULL; }
	if (index > length || index < 0) { return NULL; }
	if (index == 0) { popFront(); return NULL; }
	if (index == length - 1) { popBack(); return NULL; }

	Node* tmp;
	if (index < length / 2)
	{
		tmp = head;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (int i = length - 1; i > index; i--)
		{
			tmp = tmp->prev;
		}
	}
	Node* pop = tmp;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp = NULL;
	length--;
	return pop;
}

void MyLinkedList::printToConsole(MyLinkedList* list)
{
	Node* tmp = list->head;
	while (tmp != NULL)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

MyLinkedList::~MyLinkedList()
{
	delete head;
	delete tail;
	length = 0;
}
