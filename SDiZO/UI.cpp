#include "pch.h"
#include "UI.h"

UI::UI()
{
	myArrayListSlow = new MyArrayListSlow();
	myArrayList = new MyArrayList();
	myLinkedList = new MyLinkedList();
	myHeap = new MyHeap();
	myRedBlackTree = new MyRedBlackTree();
	command = new std::vector<std::string>;
	properties = new std::vector<std::string>;
	numbers = new std::vector<std::string>;
	mainLoop();
}

void UI::mainLoop()
{
	std::cout << "help - to help" << std::endl;
	std::cout << "$ ";
	std::string text;
	std::getline(std::cin, text);
	command = My_Environment::line_Split(text, ' ');
	if (text.empty())
	{
		std::cout << "help - to help" << std::endl;
	}
	else
	{
				if (command->at(0) == "exit")
				{
					std::cout << "exit" << std::endl;
					return;
				}
				else
				{
					if (command->at(0) == "print")
					{
						myArrayListSlow->printToFile(myArrayListSlow, "ArrayListSlow.txt");
						myArrayList->printToFile(myArrayList, "ArrayList.txt");
						myLinkedList->printToFile(myLinkedList, "LinkedList.txt");
						myHeap->printToFile(myHeap, "Heap.txt");
						myRedBlackTree->printToFile(myRedBlackTree->getRoot(), "RedBlackTree.txt");
					}
					if (command->size() >= 2)
					{
						testCompare();
					}
				}
	}
	mainLoop();
}

void UI::testCompare()
{
	if (command->at(0) == "exit")
	{
		std::cout << "exit" << std::endl;
		return;
	}
		if (command->at(1) == "-r")
		{
			if (!(command->at(2).empty()))
			{
				list = generateRandom(std::stoi(command->at(2)));
			}
		}
		if (command->at(1) == "-f")
		{
			list = readFromFile(command->at(2));
		}
		if (command->at(1) == "-o")
		{
			if (!(command->at(2).empty()))
			{
				list = generateOrder(std::stoi(command->at(2)));
			}
		}
		if (command->at(0) == "bench")
		{
			benchmark();
		}
		if (command->at(0) == "test")
		{
			tests();
		}
		if (command->at(0) == "mod")
		{
			if (command->at(1) == "-r" || command->at(1) == "-o" || command->at(1) == "-f")
			{
				if (command->size() == 4)
				{
					for (int i = 0; i < command->at(3).size(); i++)
					{
						if (command->at(3)[i] == 'a')
						{
							pushBack(myArrayList);
						}
						if (command->at(3)[i] == 's')
						{
							pushBack(myArrayListSlow);
						}
						if (command->at(3)[i] == 'l')
						{
							pushBack(myLinkedList);
						}
						if (command->at(3)[i] == 'h')
						{
							add(myHeap);
						}
						if (command->at(3)[i] == 't')
						{
							add(myRedBlackTree);
						}
					}
				}
			}
			else
			{
				properties = My_Environment::line_Split(command->at(1), '=');
				if (properties->size() == 3)
				{
					numbers = My_Environment::line_Split(properties->at(2), '/');
					if (numbers->size() == properties->at(0).size())
					{
						for (int i = 0; i < properties->at(0).length(); i++)
						{
							if (properties->at(0)[i] == 'b')
							{
								pushBack(std::stoi(numbers->at(i)));
							}
							if (properties->at(0)[i] == 'f')
							{
								pushFront(std::stoi(numbers->at(i)));
							}
							if (properties->at(0)[i] == 'B')
							{
								popBack();
							}
							if (properties->at(0)[i] == 'F')
							{
								popFront();
							}
							if (properties->at(0)[i] == 'a')
							{
								add(numbers->at(i));
							}
							if (properties->at(0)[i] == 'd')
							{
								del(std::stoi(numbers->at(i)));
							}
							if (properties->at(0)[i] == 'i')
							{
								getIndex(std::stoi(numbers->at(i)));
							}
							if (properties->at(0)[i] == 'g')
							{
								get(std::stoi(numbers->at(i)));
							}
						}
					}
					if (command->at(1) == "remove")
					{
						deleteArray();
					}
				}
			}
		}
}

void UI::benchmark()
{
	command->push_back("bBfFaid=aslht");
	tests();
}

void UI::tests()
{
	properties = My_Environment::line_Split(command->at(3), '=');
	std::cout << std::endl << "PUSH_BACK:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			testArrayList();
		}
		if (properties->at(1)[i] == 's')
		{
			testArrayListSlow();
		}
		if (properties->at(1)[i] == 'l')
		{
			testLinkedList();
		}
		if (properties->at(1)[i] == 'h')
		{
			testHeap();
		}
		if (properties->at(1)[i] == 't')
		{
			testRedBleackTree();
		}
	}
}

void UI::testArrayListSlow()
{
	std::cout << std::endl << "ArrayListSlow" << std::endl << std::endl;
	MyArrayListSlow* tmp = new MyArrayListSlow();
	for (int i = 0; i < properties->at(0).length(); i++)
	{
		if (properties->at(0)[i] == 'b')
		{
			std::cout << "PushBack" << std::endl;
			tmp = new MyArrayListSlow();
			pushBack(tmp);
			tmp->printToFile(tmp, "ArrayListSlow_PushBack.txt");
		}
		if (properties->at(0)[i] == 'f')
		{
			std::cout << "PushFront" << std::endl;
			tmp = new MyArrayListSlow();
			pushFront(tmp);
			tmp->printToFile(tmp, "ArrayListSlow_PushFront.txt");
		}
		if (properties->at(0)[i] == 'B')
		{
			std::cout << "PopBack" << std::endl;
			popBack(tmp);
		}
		if (properties->at(0)[i] == 'F')
		{
			std::cout << "PopFront" << std::endl;
			popFront(tmp);
		}
		if (properties->at(0)[i] == 'a')
		{
			std::cout << "Add" << std::endl;
			tmp = new MyArrayListSlow();
			add(tmp);
			tmp->printToFile(tmp, "ArrayListSlow_ADD.txt");
		}
		if (properties->at(0)[i] == 'd')
		{
			std::cout << "Delete" << std::endl;
			del(tmp);
		}
		if (properties->at(0)[i] == 'i')
		{
			std::cout << "Iteration" << std::endl;
			iteration(tmp);
		}
	}
	delete tmp;
}

void UI::testArrayList()
{
	std::cout << std::endl << "ArrayList" << std::endl << std::endl;
	MyArrayList* tmp = new MyArrayList();
	for (int i = 0; i < properties->at(0).length(); i++)
	{
		if (properties->at(0)[i] == 'b')
		{
			std::cout << "PushBack" << std::endl;
			tmp = new MyArrayList();
			pushBack(tmp);
			tmp->printToFile(tmp, "ArrayList_PushBack.txt");
		}
		if (properties->at(0)[i] == 'f')
		{
			std::cout << "PuahFront" << std::endl;
			tmp = new MyArrayList();
			pushFront(tmp);
			tmp->printToFile(tmp, "ArrayList_PushFront.txt");
		}
		if (properties->at(0)[i] == 'B')
		{
			std::cout << "PopBack" << std::endl;
			popBack(tmp);
		}
		if (properties->at(0)[i] == 'F')
		{
			std::cout << "PopFront" << std::endl;
			popFront(tmp);
		}
		if (properties->at(0)[i] == 'a')
		{
			std::cout << "Add" << std::endl;
			tmp = new MyArrayList();
			add(tmp);
			tmp->printToFile(tmp, "ArrayList_Add.txt");
		}
		if (properties->at(0)[i] == 'd')
		{
			std::cout << "Delete" << std::endl;
			del(tmp);
		}
		if (properties->at(0)[i] == 'i')
		{
			std::cout << "Iteration" << std::endl;
			iteration(tmp);
		}
	}
	delete tmp;
}

void UI::testLinkedList()
{
	std::cout << std::endl << "LinkedList" << std::endl << std::endl;
	MyLinkedList* tmp = new MyLinkedList();
	for (int i = 0; i < properties->at(0).length(); i++)
	{
		if (properties->at(0)[i] == 'b')
		{
			std::cout << "PushBack" << std::endl;
			tmp = new MyLinkedList();
			pushBack(tmp);
			tmp->printToFile(tmp, "LinkedList_PushBack.txt");
		}
		if (properties->at(0)[i] == 'f')
		{
			std::cout << "PushFront" << std::endl;
			tmp = new MyLinkedList();
			pushFront(tmp);
			tmp->printToFile(tmp, "LinkedList_PushFront.txt");
		}
		if (properties->at(0)[i] == 'B')
		{
			std::cout << "PopBack" << std::endl;
			popBack(tmp);
		}
		if (properties->at(0)[i] == 'F')
		{
			std::cout << "PopFront" << std::endl;
			popFront(tmp);
		}
		if (properties->at(0)[i] == 'a')
		{
			std::cout << "Add" << std::endl;
			tmp = new MyLinkedList();
			add(tmp);
			tmp->printToFile(tmp, "LinkedList_Add.txt");
		}
		if (properties->at(0)[i] == 'd')
		{
			std::cout << "Delete" << std::endl;
			del(tmp);
		}
		if (properties->at(0)[i] == 'i')
		{
			std::cout << "Iteration" << std::endl;
			iteration(tmp);
		}
	}
	delete tmp;
}

void UI::testHeap()
{
	std::cout << std::endl << "Heap" << std::endl << std::endl;
	MyHeap* tmp = new MyHeap();
	for (int i = 0; i < properties->at(0).length(); i++)
	{
		if (properties->at(0)[i] == 'a')
		{
			std::cout << "ADD" << std::endl;
			tmp = new MyHeap();
			add(tmp);
			tmp->printToFile(tmp, "Heap_Add.txt");
		}
		if (properties->at(0)[i] == 'd')
		{
			std::cout << "Delete" << std::endl;
			del(tmp);
		}
		if (properties->at(0)[i] == 'i')
		{
			std::cout << "Iteration" << std::endl;
			iteration(tmp);
		}
	}
	delete tmp;
}

void UI::testRedBleackTree()
{
	std::cout << std::endl << "RedBlackTree" << std::endl << std::endl;
	MyRedBlackTree* tmp = new MyRedBlackTree();
	for (int i = 0; i < properties->at(0).length(); i++)
	{
		if (properties->at(0)[i] == 'a')
		{
			std::cout << "ADD" << std::endl;
			tmp = new MyRedBlackTree();
			add(tmp);
			tmp->printToFile(tmp->getRoot(), "RedBlackTree_Add.txt");
		}
		if (properties->at(0)[i] == 'd')
		{
			std::cout << "Delete" << std::endl;
			//del(tmp);////////////////////////////////////////////////////////////////////////////////////////
		}
		if (properties->at(0)[i] == 'i')
		{
			std::cout << "Iteration" << std::endl;
			iteration(tmp);
		}
	}
	delete tmp;
}

void UI::printToFile(std::vector<int>* tmp, std::string fileName)
{
	std::ofstream fout;
	fout.open(fileName);
	if (fout.is_open())
	{
		std::cout << "|                                      PrintToFile vector...                                       |" << std::endl;
		std::vector<int>::iterator iter;
		int i = 0;
		timerStart();
		for (iter = tmp->begin(); iter != tmp->end(); iter++, i++)
		{
			fout << *iter << std::endl;
			if (std::stoi(command->at(2)) >= 100)
			{
				if (i % (std::stoi(command->at(2)) / 100) == 0)
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

std::vector<int>* UI::readFromFile(std::string fileName)
{
	std::vector<int>* tmp = new std::vector<int>;
	std::ifstream fin;
	fin.open(fileName);
	if (fin.is_open())
	{
		std::string s;
		while (!fin.eof())
		{
			s = "";
			fin >> s;
			if(s.size() > 0)
			tmp->push_back(std::stoi(s));
		}
	}
	else
	{
		std::cout << "ERROR file can't open" << std::endl;
	}
	fin.close();
	return tmp;
}

void UI::pushBack(int val)
{
	std::cout << std::endl << "PUSH_BACK:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if(properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->pushBack(val);
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if(properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->pushBack(val);
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if(properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			timerStart();
			myLinkedList->pushBack(val);
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if(properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			myHeap->add(val);
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if(properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			timerStart();
			myRedBlackTree->add(val);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::pushFront(int val)
{
	std::cout << std::endl << "PUSH_Front:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->pushFront(val);
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->pushFront(val);
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			timerStart();
			myLinkedList->pushFront(val);
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			myHeap->add(val);
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			timerStart();
			myRedBlackTree->add(val);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::popBack()
{
	std::cout << std::endl << "POP_BACK:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->popBack();
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->popBack();
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			timerStart();
			myLinkedList->popBack();
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			myHeap->del(myHeap->getLength() - 1);
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			RedBlackNode* tmp = myRedBlackTree->getRoot();
			while (tmp != NULL && tmp->right != NULL)
			{
				tmp = tmp->right;
			}
			timerStart();
			myRedBlackTree->del(tmp);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::popFront()
{
	std::cout << std::endl << "POP_FIRST:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->popBack();
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->popBack();
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			timerStart();
			myLinkedList->popBack();
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			myHeap->del(myHeap->getLength());
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			timerStart();
			myRedBlackTree->del(myRedBlackTree->getRoot());
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::add(std::string s)
{
	std::vector<std::string>* addIn = My_Environment::line_Split(s, ',');
	int val = std::stoi(addIn->at(0));
	int index = std::stoi(addIn->at(1));

	std::cout << std::endl << "ADD_IN:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->addIn(index, val);
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->addIn(index, val);
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			timerStart();
			myLinkedList->addIn(index, val);
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			if (index <= myHeap->getLength())
			{
				myHeap->add(val);
			}
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			timerStart();
			myRedBlackTree->add(val);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::del(int val)
{
	std::cout << std::endl << "DELETE:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		int index = -1;
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			index = myArrayList->getIndex(val);
			timerStart();
			myArrayList->del(index);
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			index = myArrayListSlow->getIndex(val);
			timerStart();
			myArrayListSlow->del(index);
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;
			index = myLinkedList->getIndex(val);
			timerStart();
			myLinkedList->del(index);
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			index = myHeap->getIndex(val);
			timerStart();
			myHeap->del(index);
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			RedBlackNode* tmp = myRedBlackTree->getNode(val);
			timerStart();
			myRedBlackTree->del(tmp);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::getIndex(int val)
{
	std::cout << std::endl << "GET_Index:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			std::cout << myArrayList->getIndex(val) << std::endl;
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			std::cout << myArrayListSlow->getIndex(val) << std::endl;
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;

			timerStart();
			std::cout << myLinkedList->getIndex(val) << std::endl;
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			std::cout << myHeap->getIndex(val) << std::endl;
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			if (myRedBlackTree->getNode(val) != NULL)
			{
				timerStart();
				std::cout << myRedBlackTree->getNode(val)->val << std::endl;
				timerStop();
			}
			else
			{
				timerStart();
				std::cout << "nie istnieje" << std::endl;
				timerStop();
			}
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::get(int index)
{
	if (index == -1024)
	{
		std::cout << std::endl << "GET:" << std::endl;
		for (int i = 0; i < properties->at(1).size(); i++)
		{
			if (properties->at(1)[i] == 'a')
			{
				std::cout << "ArrayList" << std::endl;
				timerStart();
				myArrayList->printToConsole(myArrayList);
				timerStop();
				std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
			}
			if (properties->at(1)[i] == 's')
			{
				std::cout << "ArrayListSlow" << std::endl;
				timerStart();
				myArrayListSlow->printToConsole(myArrayListSlow);
				timerStop();
				std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
			}
			if (properties->at(1)[i] == 'l')
			{
				std::cout << "LinkedList" << std::endl;

				timerStart();
				myLinkedList->printToConsole(myLinkedList);
				timerStop();
				std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
			}
			if (properties->at(1)[i] == 'h')
			{
				std::cout << "Heap" << std::endl;
				timerStart();
				myHeap->printToConsole(myHeap);
				timerStop();
				std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
			}
			if (properties->at(1)[i] == 't')
			{
				std::cout << "RedBlackTree" << std::endl;
				timerStart();
				myRedBlackTree->printToConsole(myRedBlackTree);
				timerStop();
				std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
			}
		}
	}
	else
	{
		std::cout << std::endl << "GET:" << std::endl;
		for (int i = 0; i < properties->at(1).size(); i++)
		{
			if (properties->at(1)[i] == 'a')
			{
				std::cout << "ArrayList" << std::endl;
				timerStart();
				std::cout << myArrayList->get(index) << std::endl;
				timerStop();
				std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
			}
			if (properties->at(1)[i] == 's')
			{
				std::cout << "ArrayListSlow" << std::endl;
				timerStart();
				std::cout << myArrayListSlow->get(index) << std::endl;
				timerStop();
				std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
			}
			if (properties->at(1)[i] == 'l')
			{
				std::cout << "LinkedList" << std::endl;

				timerStart();
				std::cout << myLinkedList->get(index)->data << std::endl;
				timerStop();
				std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
			}
			if (properties->at(1)[i] == 'h')
			{
				std::cout << "Heap" << std::endl;
				timerStart();
				std::cout << myHeap->get(index) << std::endl;
				timerStop();
				std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
			}
		}
	}
}

void UI::pushBack(MyArrayListSlow* tmp)
{
	std::cout << "|                                      PushBack: testing...                                        |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushBack(*iter);
		timerStopFunc("ArrSlow_PushBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::pushFront(MyArrayListSlow* tmp)
{
	std::cout << "|                                      PushFront: testing...                                       |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushFront(*iter);
		timerStopFunc("ArrSlow_PushFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popFront(MyArrayListSlow* tmp)
{
	std::cout << "|                                      PopFront: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getSize() != 0; i++)
	{
		timerStartFunc();
		tmp->popFront();
		timerStopFunc("ArrSlow_PopFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popBack(MyArrayListSlow* tmp)
{
	std::cout << "|                                      PopBack: testing...                                         |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getSize() != 0; i++)
	{
		timerStartFunc();
		tmp->popBack();
		timerStopFunc("ArrSlow_PopBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::add(MyArrayListSlow* tmp)
{
	std::cout << "|                                      AddIn: testing...                                           |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->addIn(tmp->getSize()/2, *iter);
		timerStopFunc("ArrSlow_add_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::del(MyArrayListSlow* tmp)
{
	std::cout << "|                                      DelIndex: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getSize() != 0; i++)
	{
		timerStartFunc();
		tmp->del(tmp->getSize()/2);
		timerStopFunc("ArrSlow_del_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::iteration(MyArrayListSlow* tmp)
{
	std::cout << "|                                      Iteration: testing...                                       |" << std::endl;
	timerStart();
	for (int i = 0; i < tmp->getSize() != 0; i++)
	{
		timerStartFunc();
		tmp->get(i);
		timerStopFunc("ArrSlow_iter_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::pushBack(MyArrayList* tmp)
{
	std::cout << "|                                      PushBack: testing...                                        |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushBack(*iter);
		timerStopFunc("Arr_PushBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::pushFront(MyArrayList* tmp)
{
	std::cout << "|                                      PushFront: testing...                                       |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushFront(*iter);
		timerStopFunc("Arr_PushFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popFront(MyArrayList* tmp)
{
	std::cout << "|                                      PopFront: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->popFront();
		timerStopFunc("Arr_PopFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popBack(MyArrayList* tmp)
{
	std::cout << "|                                      PopBack: testing...                                         |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->popBack();
		timerStopFunc("Arr_PopBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::add(MyArrayList* tmp)
{
	std::cout << "|                                      AddIn: testing...                                           |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->addIn(tmp->getLength() / 2, *iter);
		timerStopFunc("Arr_add_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::del(MyArrayList* tmp)
{
	std::cout << "|                                      DelIndex: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->del(tmp->getLength() / 2);
		timerStopFunc("Arr_del_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::iteration(MyArrayList* tmp)
{
	std::cout << "|                                      Iteration: testing...                                       |" << std::endl;
	timerStart();
	for (int i = 0; i < tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->get(i);
		timerStopFunc("Arr_iter_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::pushBack(MyLinkedList* tmp)
{
	timerStartFunc();
	std::cout << "|                                      PushBack: testing...                                        |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushBack(*iter);
		timerStopFunc("Link_PushBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::pushFront(MyLinkedList* tmp)
{
	std::cout << "|                                      PushFront: testing...                                       |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->pushFront(*iter);
		timerStopFunc("Link_PushFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popFront(MyLinkedList* tmp)
{
	std::cout << "|                                      PopFront: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->popFront();
		timerStopFunc("Link_PopFront_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::popBack(MyLinkedList* tmp)
{
	std::cout << "|                                      PopBack: testing...                                         |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->popBack();
		timerStopFunc("Link_PopBack_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::add(MyLinkedList* tmp)
{
	std::cout << "|                                      AddIn: testing...                                           |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->addIn(tmp->getLength() / 2, *iter);
		timerStopFunc("Link_add_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::del(MyLinkedList* tmp)
{
	std::cout << "|                                      DelIndex: testing...                                        |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->del(tmp->getLength() / 2);
		timerStopFunc("Link_del_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::iteration(MyLinkedList* tmp)
{
	std::cout << "|                                      Iteration: testing...                                       |" << std::endl;
	timerStart();
	for (int i = 0; i < tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->get(i);
		timerStopFunc("Link_iter_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getLength() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::add(MyHeap* tmp)
{
	std::cout << "|                                      ADD: testing...                                             |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->add(*iter);
		timerStopFunc("Heap_add_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::del(MyHeap* tmp)
{
	std::cout << "|                                      Del: testing...                                             |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->del(0);
		timerStopFunc("Heap_del_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::iteration(MyHeap* tmp)
{
	std::cout << "|                                      Iteration: testing...                                       |" << std::endl;
	timerStart();
	for (int i = 0; i < tmp->getLength() != 0; i++)
	{
		timerStartFunc();
		tmp->get(i);
		timerStopFunc("Heap_iter_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getLength() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::add(MyRedBlackTree* tmp)
{
	std::cout << "|                                      ADD: testing...                                             |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->add(*iter);
		timerStopFunc("RedBlackTree_add_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::del(MyRedBlackTree* tmp)
{
	std::cout << "|                                      Del: testing...                                             |" << std::endl;
	timerStart();
	for (int i = 0; tmp->getSize() != 0; i++)
	{
		timerStartFunc();
		tmp->del(tmp->getRoot());
		timerStopFunc("RedBlackTree_del_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::iteration(MyRedBlackTree* tmp)
{
	std::cout << "|                                      Iteration: testing...                                       |" << std::endl;
	std::vector<int>::iterator iter;
	int i = 0;
	timerStart();
	for (iter = list->begin(); iter != list->end(); iter++, i++)
	{
		timerStartFunc();
		tmp->getNode(*iter);
		timerStopFunc("RBT_iter_time.txt");
		if (list->size() >= 100)
		{
			if (i % (list->size() / 100) == 0)
			{
				std::cout << "#";
			}
		}
		else
		{
			std::cout << "#";
		}
	}
	std::cout << std::endl;
	//tmp->printToConsole(tmp);
	std::cout << "lenght = " << tmp->getSize() << "	size = " << tmp->getSize() << std::endl;
	std::cout << "completed.	";
	timerStopP();
}

void UI::timerStart()
{
	time.time_Start();
}

void UI::timerStopP()
{
	time.time_End();
	std::cout << "time = " << time.getTime() << std::endl;
	time.printResult("TIME_ALL.txt");
}

void UI::timerStop()
{
	time.time_End();
	std::cout << "time = " << time.getTime() << std::endl;
}

void UI::timerStopFunc(std::string fileName)
{
	timeFunc.time_End();
	//std::cout << "time = " << time.getTime() << std::endl;
	timeFunc.printResult(fileName);
}

void UI::timerStartFunc()
{
	timeFunc.time_Start();
}

std::vector<int>* UI::generateRandom(const int& number)
{
	std::vector<int>* tmp = new std::vector<int>;
	for (int i = 0; i < number; i++)
	{
		tmp->push_back(rand());
	}
	printToFile(tmp, "random_vector.txt");
	return tmp;
}

std::vector<int>* UI::generateOrder(const int& number)
{
	std::vector<int>* tmp = new std::vector<int>;
	for (int i = 0; i < number; i++)
	{
		tmp->push_back(i);
	}
	printToFile(tmp, "order_vector.txt");
	return tmp;
}

void UI::deleteArray()
{
	for (int i = 0; i < command->at(2).size(); i++)
	{
		if (command->at(2)[i] == 'a')
		{
			myArrayList = new MyArrayList();
		}
		if (command->at(2)[i] == 's')
		{
			myArrayListSlow = new MyArrayListSlow();
		}
		if (command->at(2)[i] == 'l')
		{
			myLinkedList = new MyLinkedList();
		}
		if (command->at(2)[i] == 'h')
		{
			myHeap = new MyHeap();
		}
		if (command->at(2)[i] == 't')
		{
			myRedBlackTree = new MyRedBlackTree();
		}
	}
	std::cout << "remove is completed" << std::endl;
}
