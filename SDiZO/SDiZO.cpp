// SDiZO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include "MyArrayListSlow.h"
#include "MyArrayList.h"
#include "MyLinkedList.h"
#include "MyHeap.h"
#include "MyRedBlackTree.h"

int main()
{
	//srand(time(0));
	MyRedBlackTreee* myHeap = new MyRedBlackTreee();
	for (int i = 0; i < 1; i++)
	{
		myHeap->add(rand());
	}
	myHeap->printToConsole(myHeap);
	std::cout << std::endl << std::endl;
	myHeap->del(myHeap->getNode(41));
	myHeap->printToConsole(myHeap);

	for (int i = 0; i < 1; i++)
	{
		myHeap->add(rand());
	}
	myHeap->printToConsole(myHeap);

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
