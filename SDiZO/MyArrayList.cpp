#include "pch.h"
#include "MyArrayList.h"

MyArrayList::MyArrayList()
{
	lenght = 0;
	size = 0;
}

void MyArrayList::pushBack(int val)
{
	if (array == NULL) 
	{
		size++;
		array = new int[size];
		array[0] = val;
		lenght++;
		return;
	}
	if (lenght == size)
	{
		int* tmp = array;
		size = size * 2;
		array = new int[size];
		for (int i = 0; i < lenght; i++)
		{
			array[i] = tmp[i];
		}
		delete[] tmp;
	}
	array[lenght] = val;
	lenght++;
}

void MyArrayList::pushFront(int val)
{
	if (array == NULL)
	{
		size++;
		array = new int[size];
		array[0] = val;
		lenght++;
		return;
	}
	if (lenght == size)
	{
		int* tmp = array;
		size = size * 2;
		array = new int[size];
		for (int i = 0; i < lenght; i++)
		{
			array[i] = tmp[i];
		}
		delete[] tmp;
	}
	array[0] = val;
	lenght++;
}
