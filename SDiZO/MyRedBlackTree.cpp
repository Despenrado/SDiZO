#include "pch.h"
#include "MyRedBlackTree.h"

MyRedBlackTree::MyRedBlackTree()
{
	stage = 0;
	size = 0;
}

void MyRedBlackTree::add(int val)
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

int MyRedBlackTree::getSize()
{
	return size;
}

RedBlackNode* MyRedBlackTree::getNode(int val)
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

RedBlackNode* MyRedBlackTree::getRoot()
{
	return root;
}

void MyRedBlackTree::printToConsole(MyRedBlackTree* tmp)
{
	tmp->preorder(tmp->root);
}

RedBlackNode* MyRedBlackTree::preorder(RedBlackNode* tmp)
{
	if (tmp == NULL) { return NULL; }
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 15);
	if (tmp->color)
	{
		SetConsoleTextAttribute(hStdOut, 4);
	}
	std::cout << tmp->val << std::endl;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 15);
	preorder(tmp->left);
	preorder(tmp->right);
}

void MyRedBlackTree::del(RedBlackNode* rm)
{
	if (rm == NULL) { return; }
	rm = replace(rm);
	if (rm->color == false)
	{
		if (rm->right == NULL)
		{
			deleteCase1(rm);
		}
	}
	if (rm != root) {
		if (rm->right == NULL)
		{
			rm->prev->left = NULL;
		}
		else
		{
			rm->val = rm->right->val;
			rm->right = NULL;
		}
	}
	else
	{
		root = NULL;
	}
	rm = NULL;
	delete rm;
	size--;
}

void MyRedBlackTree::printToFile(RedBlackNode* tmp, std::string fileName)
{
	if (tmp == NULL) { return; }
	std::ofstream fout;
	fout.open(fileName, std::ofstream::app);
	fout << tmp->val << std::endl;
	fout.close();
	printToFile(tmp->left, fileName);
	printToFile(tmp->right, fileName);
}


MyRedBlackTree::~MyRedBlackTree()
{
	delete root;
	size = 0;
	stage = 0;
}

void MyRedBlackTree::leftRotation(RedBlackNode* n)
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

void MyRedBlackTree::rightRotation(RedBlackNode* n)
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

RedBlackNode* MyRedBlackTree::insert(RedBlackNode* tmp, int val)
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

void MyRedBlackTree::insertCase1(RedBlackNode* tmp)
{
	if (tmp->prev == NULL)
	{
		tmp->color = false;
		return;
	}
	insertCase2(tmp);
}

void MyRedBlackTree::insertCase2(RedBlackNode* tmp)
{
	if (tmp->prev->color == false)
	{
		return;
	}
	insertCase3(tmp);
}

void MyRedBlackTree::insertCase3(RedBlackNode* tmp)
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

void MyRedBlackTree::insertCase4(RedBlackNode* tmp)
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

void MyRedBlackTree::insertCase5(RedBlackNode* tmp)
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

RedBlackNode* MyRedBlackTree::replace(RedBlackNode* tmp_root)
{
	RedBlackNode* tmp = tmp_root;
	if (tmp_root->right != NULL)
	{
		tmp = tmp_root->right;
		while (tmp->left != NULL)
		{
			tmp = tmp->left;
		}
	}
	tmp_root->val = tmp->val;
	return tmp;
}

void MyRedBlackTree::deleteCase1(RedBlackNode* tmp)
{
		if (tmp->prev != NULL)
		{
			deleteCase2(tmp);
		}
}

void MyRedBlackTree::deleteCase2(RedBlackNode* tmp)
{
	RedBlackNode* brother = sibling(tmp);
	if (brother->color == true) {
		tmp->prev->color = true;
		brother->color = false;
		if (tmp == tmp->prev->left)
			leftRotation(tmp->prev);
		else
			rightRotation(tmp->prev);
	}
	deleteCase3(tmp);
}

void MyRedBlackTree::deleteCase3(RedBlackNode* n)
{
	RedBlackNode* s = sibling(n);

	if ((n->prev->color == false) && (s->color == false) &&
		(s->left->color == false) && (s->right->color == false)) {
		s->color = true;
		deleteCase1(n->prev);
	}
	else
		deleteCase4(n);
}

void MyRedBlackTree::deleteCase4(RedBlackNode* n)
{
	RedBlackNode* s = sibling(n);

	if ((n->prev->color == true) && (s->color == false) && ((s->left == NULL || (s->left->color == false)) &&
		(s->right == NULL ||(s->right->color == false)))) {
		s->color = true;
		n->prev->color = false;
	}
	else
		deleteCase5(n);
}

void MyRedBlackTree::deleteCase5(RedBlackNode* n)
{
	RedBlackNode* s = sibling(n);

	if (s->color == false) {
		if ((n == n->prev->left) &&
			(s->right->color == false) &&
			(s->left->color == true)) { /* this last test is trivial too due to cases 2-4. */
			s->color = true;
			s->left->color = false;
			rightRotation(s);
		}
		else if ((n == n->prev->right) &&
			(s->left->color == false) &&
			(s->right->color == true)) {/* this last test is trivial too due to cases 2-4. */
			s->color = true;
			s->right->color = false;
			leftRotation(s);
		}
	}
	deleteCase6(n);
}

void MyRedBlackTree::deleteCase6(RedBlackNode* n)
{
	RedBlackNode* s = sibling(n);

	s->color = n->prev->color;
	n->prev->color = false;

	if (n == n->prev->left) {
		s->right->color = false;
		leftRotation(n->prev);
	}
	else {
		s->left->color = false;
		rightRotation(n->prev);
	}
}

RedBlackNode* MyRedBlackTree::sibling(RedBlackNode* n)
{
	if (n == n->prev->left)
		return n->prev->right;
	else
		return n->prev->left;
}



//void MyRedBlackTreee::deleteRedLeaf(RedBlackNode* rm)
//{
//	if (rm == rm->prev->left)
//	{
//		rm->prev->left = NULL;
//		return;
//	}
//	rm->prev->right = NULL;
//}
//
//void MyRedBlackTreee::deleteBlackLeaf(RedBlackNode* rm)
//{
//	if (rm->prev->color == true)
//	{
//		deleteCase1(rm);
//	}
//	else
//	{
//		deleteCase2(rm);
//	}
//}
//
//void MyRedBlackTreee::deleteCase1(RedBlackNode* rm)
//{
//	RedBlackNode* pstmp = rm->prev->left;
//	rm->prev->right = NULL;
//	if (pstmp->left != NULL && pstmp->right != NULL)
//	{
//		if (pstmp->left != NULL && pstmp->left->color == true)
//		{
//			pstmp->prev->color = false;
//			pstmp->color = true;
//			pstmp->left->color = false;
//			rightRotation(pstmp->prev);
//		}
//		else
//		{
//			if (pstmp->right != NULL && pstmp->right->color == true)
//			{
//				pstmp->prev->color = false;
//				pstmp->color = false;
//				pstmp->right->color = true;
//				leftRotation(pstmp);
//				rightRotation(pstmp->prev);
//			}
//			else
//			{
//				pstmp->prev->color = false;
//				pstmp->color = true;
//			}
//		}
//	}
//	else
//	{
//		pstmp->prev->color = false;
//		pstmp->color = true;
//	}
//}
//
//void MyRedBlackTreee::deleteCase2(RedBlackNode* rm)
//{
//	RedBlackNode* pstmp = rm->prev->left;
//	rm->prev->right = NULL;
//	if (pstmp != NULL && pstmp->color == true)
//	{
//		if(pst)
//	}
//	
//}

