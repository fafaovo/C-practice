#include <iostream>
using namespace std;

typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE * lchild;
	struct BINARYNODE * rchild;
}BinaryNode, *pBinaryNode;

void Recursion1(pBinaryNode root)
{
	if (root == NULL)
		return;
	cout << root->ch << " ";
	Recursion1(root->lchild);
	Recursion1(root->rchild);
}
void Recursion2(pBinaryNode root)
{
	if (root == NULL)
		return;	
	Recursion2(root->lchild);
	cout << root->ch << " ";
	Recursion2(root->rchild);
}


pBinaryNode CreateBinaryTree()
{
	char ch;
	cin >> ch;
	pBinaryNode node;
	pBinaryNode lchlid;
	pBinaryNode rchlid;


	if (ch == '#')
	{
		node = NULL;
	}
	else
	{
		node = new BinaryNode();
		node->ch = ch;
		node->lchild = CreateBinaryTree();
		node->rchild = CreateBinaryTree();
	}
	
	return node;
}

int main()
{
	pBinaryNode root= CreateBinaryTree();
	Recursion1(root);
	cout << endl;
	Recursion2(root);
	cout << endl;
	system("pause");
	return 0;
}