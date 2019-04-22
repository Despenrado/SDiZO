#include "pch.h"
#include "MyRedBlackTree.h"

MyRedBlackTreee::MyRedBlackTreee()
{
	stage = 0;
	size = 0;
}

void MyRedBlackTreee::add(int val)
{
	RedBlackNode* newNode = new RedBlackNode();
	newNode->val = val;
	newNode->color = true;
	newNode->left = NULL;
	newNode->right = NULL;

	RedBlackNode* tmp = insert(root, val);
	if (tmp == NULL)
	{
		newNode->prev = NULL;
		root = newNode;
	}
	else
	{
		newNode->prev = tmp;
		if (tmp->val > val)
		{
			tmp->left = newNode;
		}
		else
		{
			tmp->right = newNode;
		}
	}
	insertCase1(newNode);
	size++;
}

int MyRedBlackTreee::getSize()
{
	return size;
}

RedBlackNode* MyRedBlackTreee::getNode(int val)
{
	RedBlackNode* tmp = root;
	while (tmp != NULL)
	{
		if (tmp->val == val)
		{
			return tmp;
		}
		if (tmp->val > val)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	return NULL;
}

void MyRedBlackTreee::printToConsole(MyRedBlackTreee* tmp)
{
	tmp->preorder(tmp->root);
}

RedBlackNode* MyRedBlackTreee::preorder(RedBlackNode* tmp)
{
	if (tmp == NULL) { return NULL; }
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 15);
	if (tmp->color)
	{
		SetConsoleTextAttribute(hStdOut, 4);
	}

	std::cout << tmp->val << "  ";
	preorder(tmp->left);
	preorder(tmp->right);
}

void MyRedBlackTreee::del(int)
{
}

void MyRedBlackTreee::leftRotation(RedBlackNode* n)
{
	RedBlackNode* tmp = n->right;

	tmp->prev = n->prev;
	if (n->prev != NULL)
	{
		if (n->prev->left == n)
		{
			n->prev->left = tmp;
		}
		else
		{
			n->prev->right = tmp;
		}
	}
	else
	{
		root = tmp;
	}
	n->right = tmp->left;
	if (tmp->left != NULL)
	{
		tmp->left->prev = n;
	}
	n->prev = tmp;
	tmp->left = n;
}

void MyRedBlackTreee::rightRotation(RedBlackNode* n)
{
	RedBlackNode* tmp = n->left;

	tmp->prev = n->prev;
	if (n->prev != NULL)
	{
		if (n->prev->left == n)
		{
			n->prev->left = tmp;
		}
		else
		{
			n->prev->right = tmp;
		}
	}
	else
	{
		root = tmp;
	}
	n->left = tmp->right;
	if (tmp->right != NULL)
	{
		tmp->right->prev = n;
	}
	n->prev = tmp;
	tmp->right = n;
}

RedBlackNode* MyRedBlackTreee::insert(RedBlackNode* tmp, int val)
{
	if (tmp == NULL)
	{
		return NULL;
	}
	if (tmp->val > val)
	{
		if (tmp->left == NULL)
		{
			return tmp;
		}
		return insert(tmp->left, val);
	}
	if (tmp->right == NULL)
	{
		return tmp;
	}
	return insert(tmp->right, val);
}

void MyRedBlackTreee::insertCase1(RedBlackNode* tmp)
{
	if (tmp->prev == NULL)
	{
		tmp->color = false;
		return;
	}
	insertCase2(tmp);
}

void MyRedBlackTreee::insertCase2(RedBlackNode* tmp)
{
	if (tmp->prev->color == false)
	{
		return;
	}
	insertCase3(tmp);
}

void MyRedBlackTreee::insertCase3(RedBlackNode* tmp)
{
	RedBlackNode* utmp;
	RedBlackNode* gptmp;
	if (tmp != NULL && tmp->prev != NULL)
	{
		utmp = tmp->prev->prev;
		gptmp = tmp->prev->prev;
	}
	else
	{
		utmp = NULL;
		gptmp = NULL;
	}
	if (utmp != NULL)
	{
		if (tmp->prev == utmp->left)
		{
			utmp = utmp->right;
		}
		else
		{
			utmp = utmp->left;
		}
	}
	if (utmp != NULL && utmp->color == true)
	{
		tmp->prev->color = false;
		utmp->color = false;
		gptmp->color = true;
		insertCase1(gptmp);
	}
	else
	{
		insertCase4(tmp);
	}
}

void MyRedBlackTreee::insertCase4(RedBlackNode* tmp)
{
	RedBlackNode* gptmp;
	if(tmp != NULL && tmp->prev != NULL)
	{
		gptmp = tmp->prev->prev;
	}
	else
	{
		gptmp = NULL;
	}

	if (tmp == tmp->prev->right && tmp->prev == gptmp->left)
	{
		leftRotation(tmp->prev);
		tmp = tmp->left;
	}
	else 
	{
		if (tmp == tmp->prev->left && tmp->prev == gptmp->right)
		{
			rightRotation(tmp->prev);
			tmp = tmp->right;
		}
	}
	insertCase5(tmp);
}

void MyRedBlackTreee::insertCase5(RedBlackNode* tmp)
{
	RedBlackNode* gptmp;
	if (tmp != NULL && tmp->prev != NULL)
	{
		gptmp = tmp->prev->prev;
		tmp->prev->color = false;
		gptmp->color = true;
	}
	else
	{
		gptmp = NULL;
	}

	if ((tmp == tmp->prev->left) && (tmp->prev == gptmp->left)) {
		rightRotation(gptmp);
	}
	else { // (n == n->parent->right) && (n->parent == g->right)
		leftRotation(gptmp);
	}
}
