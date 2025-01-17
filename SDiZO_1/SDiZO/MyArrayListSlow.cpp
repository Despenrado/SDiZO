#include "pch.h"
#include "MyArrayListSlow.h"

MyArrayListSlow::MyArrayListSlow()
{
	size = 0;
}

void MyArrayListSlow::pushBack(int val)
{
	if (array == NULL || size == 0)
	{
		size++;
		array = new int[size];
		array[0] = val;
		return;
	}
	int* tmp = array;
	array = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	delete[] tmp;
	array[size] = val;
	size++;
}

void MyArrayListSlow::pushFront(int val)
{
	if (array == NULL || size == 0)
	{
		size++;
		array = new int[size];
		array[0] = val;
		return;
	}
	int* tmp = array;
	array = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		array[i + 1] = tmp[i];
	}
	delete[] tmp;
	array[0] = val;
	size++;
}

void MyArrayListSlow::addIn(int number, int val)
{
	if (number > size) { return; }
	if (number == 0) { pushFront(val); return; }
	if (number == 0) { pushFront(val); return; }
	if (array == NULL || size == 0)
	{
		size++;
		array = new int[size];
		array[0] = val;
		return;
	}
	int* tmp = array;
	array = new int[size + 1];
	for (int i = 0; i < number; i++)
	{
		array[i] = tmp[i];
	}
	array[number] = val;
	for (int i = number; i < size; i++)
	{
		array[i + 1] = tmp[i];
	}
	delete[] tmp;
	size++;
}

int MyArrayListSlow::getIndex(int val)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == val) { return i; }
	}
	return -1;
}

int MyArrayListSlow::popBack()
{
	if (array == NULL || size == 0) { return -1; }
	size--;
	int tmp_val = array[size];
	int* tmp = array;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	delete[] tmp;
	return tmp_val;
}

int MyArrayListSlow::popFront()
{
	if (array == NULL || size == 0) { return -1; }
	size--;
	int tmp_val = array[0];
	int* tmp = array;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = tmp[i + 1];
	}
	delete[] tmp;
	return tmp_val;
}

int MyArrayListSlow::del(int index)
{
	if (array == NULL || size == 0) { return -1; }
	if (index > size - 1 || index < 0) { return -1; }
	if (index == 0) { return popFront(); }
	if (index == size - 1) { return popBack(); }
	size--;
	int* tmp = array;
	array = new int[size];
	for (int i = 0; i < index; i++)
	{
		array[i] = tmp[i];
	}
	for (int i = index + 1; i < size + 1; i++)
	{
		array[i - 1] = tmp[i];
	}
	int tmp_val = tmp[index];
	delete[] tmp;
	return tmp_val;
}

int MyArrayListSlow::get(int index)
{
	if (index < 0 || index >= size) { return NULL; }
	return array[index];
}

void MyArrayListSlow::printToConsole(MyArrayListSlow* tmp)
{
	if (tmp == NULL) { return; }
	for (int i = 0; i < tmp->size; i++)
	{
		std::cout << tmp->array[i] << std::endl;
	}
}

void MyArrayListSlow::printToFile(MyArrayListSlow* tmp, std::string fileName)
{
	std::cout << "|                                      PrintToFile ArrayListSlow...                                |" << std::endl;
	std::ofstream fout;
	fout.open(fileName);
	if (fout.is_open())
	{
		for (int i = 0; i < tmp->getSize(); i++)
		{
			fout << tmp->array[i] << std::endl;
			if (tmp->getSize() >= 100)
			{
				if (i % (tmp->getSize() / 100) == 0)
				{
					std::cout << "#";
				}
			}
			else
			{
				std::cout << "#";
			}
		}
	}
	else
	{
		std::cout << "ERROR at print to file" << std::endl;
	}
	fout.close();
	std::cout << std::endl << "successful" << std::endl;
}

int MyArrayListSlow::getSize()
{
	return size;
}

MyArrayListSlow::~MyArrayListSlow()
{
	size = 0;
	delete[] array;
}
