#include <iostream>
#include <Windows.h>

struct RedBlackNode
{
	RedBlackNode* prev;
	RedBlackNode* left;
	RedBlackNode* right;
	int val;
	bool color; //false - black, true - red
};

class MyRedBlackTreee
{
public:
	MyRedBlackTreee();
	void add(int);
	int getSize();
	RedBlackNode* getNode(int);
	static void printToConsole(MyRedBlackTreee*);
	RedBlackNode* preorder(RedBlackNode*);
	void del(RedBlackNode*);

	RedBlackNode* insert(RedBlackNode*, int);
	void insertCase1(RedBlackNode*);
	void insertCase2(RedBlackNode*);
	void insertCase3(RedBlackNode*);
	void insertCase4(RedBlackNode*);
	void insertCase5(RedBlackNode*);

	RedBlackNode* replace(RedBlackNode*);
	void deleteCase1(RedBlackNode*);
	void deleteCase2(RedBlackNode*);
	void deleteCase3(RedBlackNode*);
	void deleteCase4(RedBlackNode*);
	void deleteCase5(RedBlackNode*);
	void deleteCase6(RedBlackNode*);
	RedBlackNode* sibling(RedBlackNode*);

	void leftRotation(RedBlackNode*);
	void rightRotation(RedBlackNode*);
	RedBlackNode* getSub(RedBlackNode*);


	~MyRedBlackTreee();

private:
	RedBlackNode* root;
	int stage;
	int size;
};
