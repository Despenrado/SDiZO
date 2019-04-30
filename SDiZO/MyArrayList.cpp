#include "pch.h"
#include "MyArrayList.h"

MyArrayList::MyArrayList()
{
	length = 0;
	size = 0;
}

void MyArrayList::pushBack(int val)
{
	if (array == NULL || size == 0)
	{
		size++;
		array = new int[size];
		array[0] = val;
		length++;
		return;
	}

	if (length == size)
	{
		int* tmp = array;
		size = size * 2;
		array = new int[size];
		for (int i = 0; i < length; i++)
		{
			array[i] = tmp[i];
		}
		delete[] tmp;
	}
	array[length] = val;
	length++;
}

void MyArrayList::pushFront(int val)
{
	if (array == NULL || size == 0)
	{
		size++;
		array = new int[size];
		array[0] = val;
		length++;
		return;
	}

	int* tmp = array;
	if (length == size)
	{
		size = size * 2;
		array = new int[size];
	}

	for (int i = length - 1; i >= 0; i--)
	{
		array[i + 1] = tmp[i];
	}
	array[0] = val;
	length++;
}

void MyArrayList::addIn(int number, int val)
{
	if (number > length || number < 0) { return; }
	if (number == 0) { pushFront(val); return; }
	if (number == length) { pushBack(val); return; }
	if (array == NULL || size == 0L)
	{
		size++;
		array = new int[size];
		array[0] = val;
		length++;
		return;
	}

	int* tmp = array;
	if (length == size)
	{
		size = size * 2;
		array = new int[size];
		for (int i = 0; i < number; i++)
		{
			array[i] = tmp[i];
		}
	}

	for (int i = length - 1; i >= number; i--)
	{
		array[i + 1] = tmp[i];
	}
	array[number] = val;
	length++;
}

int MyArrayList::getIndex(int val)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == val) { return i; }
	}
	return -1;
}

int MyArrayList::popBack()
{
	if (length == 0 || array == NULL) { return -1; }
	length--;
	return array[length];
}

int MyArrayList::popFront()
{
	if (length == 0 || array == NULL) { return -1; }

	int tmp = array[0];
	int* tmp_arr = array;
	length--;
	array = new int[length];
	for (int  i = 0; i < length; i++)
	{
		array[i] = tmp_arr[i + 1];
	}
	delete[] tmp_arr;
	return tmp;
}

int MyArrayList::del(int index)
{
	if (array == NULL || length == 0) { return -1; }
	if (index > length - 1 || index < 0) { return -1; }
	if (index == 0) { return popFront(); }
	if (index == size - 1) { return popBack(); }

	int* tmp = array;
	for (int i = index + 1; i < length; i++)
	{
		array[i - 1] = tmp[i];
	}
	int tmp_val = tmp[index];
	length--;
	return tmp_val;
}

int MyArrayList::get(int index)
{
	if (index < 0 || index >= length) { return NULL; }

	return array[index];
} 

void MyArrayList::printToConsole(MyArrayList* tmp)
{
	if (tmp == NULL) { return; }

	for (int i = 0; i < tmp->length; i++)
	{
		std::cout << tmp->array[i] << std::endl;
	}
}

int MyArrayList::getLength()
{
	return length;
}

int MyArrayList::getSize()
{
	return size;
}

void MyArrayList::printToFile(MyArrayList* tmp, std::string fileName)
{
	std::cout << "|                                      PrintToFile ArrayList...                                    |" << std::endl;
	std::ofstream fout;
	fout.open(fileName);
	if (fout.is_open())
	{
		for (int i = 0; i < tmp->getLength(); i++)
		{
			fout << tmp->array[i] << std::endl;
			if (tmp->getLength() >= 100)
			{
				if (i % (tmp->getLength() / 100) == 0)
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

MyArrayList::~MyArrayList()
{
	length = 0;
	size = 0;
	delete[] array;
}
