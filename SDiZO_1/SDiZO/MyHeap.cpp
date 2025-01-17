#include "pch.h"
#include "MyHeap.h"

MyHeap::MyHeap()
{
	size = 0;
	length = 0;
}

void MyHeap::add(int val)
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
	correctionAdd();
}

int MyHeap::getIndex(int val)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == val) { return i; }
	}
	return -1;
}

int MyHeap::get(int index)
{
	if (index < 0 || index >= length) { return -1; }
	return array[index];
}

int MyHeap::getSize()
{
	return size;
}

int MyHeap::getLength()
{
	return length;
}

void MyHeap::printToConsole(MyHeap *tmp)
{
	int degree = 1;
	for (int i = 0; i < tmp->getLength(); i++)
	{
		std::cout << tmp->array[i] << " ";
		if (i % 2 == 0) {
			std::cout << "| ";
		}
		if (i + 2 == pow(2, degree))
		{
			degree++;
			if (i != 1)
			{
				std::cout << std::endl;
			}
		}
	}
}

void MyHeap::printToFile(MyHeap* tmp, std::string fileName)
{
	std::cout << "|                                      PrintToFile HyHeap...                                       |" << std::endl;
	std::ofstream fout, fout2;
	fout.open(fileName);
	fout2.open("img_"+fileName);
	int degree = 1;
	if (fout.is_open() && fout2.is_open())
	{
		for (int i = 0; i < tmp->getLength(); i++)
		{
			fout << tmp->get(i) << std::endl;
			fout2 << tmp->array[i] << " ";
			if (i % 2 == 0) {
				fout2 << "| ";
			}
			if (i + 2 == pow(2, degree))
			{
				degree++;
				if (i != 1)
				{
					fout2 << std::endl;
				}
			}
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
	fout2.close();
	std::cout << std::endl << "successful" << std::endl;
}

void MyHeap::del(int index)
{
	if (index < 0 || index >= length) { return; }

	array[index] = array[length - 1];
	length--;
	correctHeap();
}

void MyHeap::correctionDown(int index)
{
	if (index >= length) { return; }
	if (index * 2 + 2 < length)
	{
		if (array[(index * 2) + 1] > array[(index * 2) + 2])
		{
			if (array[index] < array[(index * 2) + 1])
			{
				int tmp = array[index];
				array[index] = array[(index * 2) + 1];
				array[(index * 2) + 1] = tmp;
				correctionDown((index * 2) + 1);
			}
		}
		else
		{
			if (array[index] < array[(index * 2) + 2])
			{
				int tmp = array[index];
				array[index] = array[(index * 2) + 2];
				array[(index * 2) + 2] = tmp;
				correctionDown((index * 2) + 2);
			}
		}
	}
}

void MyHeap::correctHeap()
{
	int lenght2 = length;
	if (length % 2 == 0)
	{
		lenght2--;
		if (array[lenght2] > array[(lenght2 - 1) / 2])
		{
			int tmp = array[lenght2];
			array[lenght2] = array[(lenght2 - 1) / 2];
			array[(lenght2 - 1) / 2] = tmp;
		}
	}
	for (int i = lenght2 - 1; i > 0; i -= 2)
	{
		if (array[i] >= array[i - 1])
		{
			if (array[i] > array[(i - 1) / 2])
			{
				int tmp = array[i];
				array[i] = array[(i - 1) / 2];
				array[(i - 1) / 2] = tmp;
				correctionDown(i);
			}
		}
		else
		{
			if (array[i - 1] > array[(i - 1) / 2])
			{
				int tmp = array[i - 1];
				array[i - 1] = array[(i - 1) / 2];
				array[(i - 1) / 2] = tmp;
				correctionDown(i - 1);
			}
		}
	}
}

void MyHeap::correctionAdd()
{
	int lenght2 = length;
	if (length % 2 == 0)
	{
		lenght2--;
		if (array[lenght2] > array[(lenght2 - 1) / 2])
		{
			int tmp = array[lenght2];
			array[lenght2] = array[(lenght2 - 1) / 2];
			array[(lenght2 - 1) / 2] = tmp;
		}
	}
	for (int i = lenght2 - 1; i > 0; i -= 2)
	{
		if (array[i] >= array[i - 1])
		{
			if (array[i] > array[(i - 1) / 2])
			{
				int tmp = array[i];
				array[i] = array[(i - 1) / 2];
				array[(i - 1) / 2] = tmp;
			}
		}
		else
		{
			if (array[i - 1] > array[(i - 1) / 2])
			{
				int tmp = array[i - 1];
				array[i - 1] = array[(i - 1) / 2];
				array[(i - 1) / 2] = tmp;
			}
		}
	}
}

MyHeap::~MyHeap()
{
	size = 0;
	length = 0;
	delete[] array;
}
