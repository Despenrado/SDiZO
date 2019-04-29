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
		if (command->at(0) == "bench")
		{
			testCompare();
		}
		else
		{
			if (command->at(0) == "-r" || command->at(0) == "-s" || command->at(0) == "-f" || command->at(0) == "-o")
			{
				testCompare();
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
					std::cout << "help - to help" << std::endl;
				}
			}
		}
	}
	mainLoop();
}

void UI::testCompare()
{
		if (command->at(0) == "-r")
		{
			//list = generateRandom(std::stoi(command[1]));
		}
		if (command->at(0) == "-f")
		{
			//list = generateOrder(std::stoi(command[1]));
		}
		if (command->at(0) == "-o")
		{
			for (int i = 0; i < std::stoi(command->at(1)); i++)
			{
				list->push_back(i);
			}
		}
		if (command->at(0) == "-s")
		{
			properties = My_Environment::line_Split(command->at(1), '=');
			numbers = My_Environment::line_Split(properties->at(2), '/');
			try
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
			catch(int a)
			{
				std::cout << "ERROR -s" << std::endl;
			}
		}
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
			//myRedBlackTree->add(val);
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
			//myRedBlackTree->add(val);
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
			//myRedBlackTree->del(tmp);
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
			//myRedBlackTree->del(myRedBlackTree->getRoot());
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
			//myRedBlackTree->add(val);
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
			//myRedBlackTree->del(tmp);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::getIndex(int index)
{
	std::cout << std::endl << "GET_Index:" << std::endl;
	for (int i = 0; i < properties->at(1).size(); i++)
	{
		int index = -1;
		if (properties->at(1)[i] == 'a')
		{
			std::cout << "ArrayList" << std::endl;
			timerStart();
			myArrayList->getIndex(index);
			timerStop();
			std::cout << "lenght = " << myArrayList->getLength() << ";  size = " << myArrayList->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 's')
		{
			std::cout << "ArrayListSlow" << std::endl;
			timerStart();
			myArrayListSlow->getIndex(index);
			timerStop();
			std::cout << "lenght = " << myArrayListSlow->getSize() << ";  size = " << myArrayListSlow->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 'l')
		{
			std::cout << "LinkedList" << std::endl;

			timerStart();
			myLinkedList->getIndex(index);
			timerStop();
			std::cout << "lenght = " << myLinkedList->getLength() << ";  size = " << myLinkedList->getLength() << std::endl;
		}
		if (properties->at(1)[i] == 'h')
		{
			std::cout << "Heap" << std::endl;
			timerStart();
			myHeap->getIndex(index);
			timerStop();
			std::cout << "lenght = " << myHeap->getLength() << ";  size = " << myHeap->getSize() << std::endl;
		}
		if (properties->at(1)[i] == 't')
		{
			std::cout << "RedBlackTree" << std::endl;
			timerStart();
			//myRedBlackTree->printToConsole(myRedBlackTree);
			timerStop();
			std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
		}
	}
}

void UI::get(int index)
{
	if (index = -1024)
	{
		std::cout << std::endl << "GET:" << std::endl;
		for (int i = 0; i < properties->at(1).size(); i++)
		{
			int index = -1;
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
				//myRedBlackTree->printToConsole(myRedBlackTree);
				timerStop();
				std::cout << "lenght = " << myRedBlackTree->getSize() << ";  size = " << myRedBlackTree->getSize() << std::endl;
			}
		}
	}
}

void UI::timerStart()
{
	time = clock();
}

void UI::timerStop()
{
	std::cout << "time = " << clock() - time << std::endl;
}

std::vector<int>* UI::generateRandom(const int& number)
{
	std::vector<int>* tmp = new std::vector<int>;
	for (int i = 0; i < number; i++)
	{
		tmp->push_back(rand());
	}
	return tmp;
}

std::vector<int>* UI::generateOrder(const int& number)
{
	std::vector<int>* tmp = new std::vector<int>;
	for (int i = 0; i < number; i++)
	{
		tmp->push_back(i);
	}
	return nullptr;
}
