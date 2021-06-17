#include <iostream>
using namespace std;


typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE * lchild;
	struct BINARYNODE * rchild;
}BinaryNode, *pBinaryNode;

//二叉树的非递归遍历
void NonRecursion(pBinaryNode root)
{
	if (root == NULL)
		return;
	pBinaryNode Treestack[10];
	int StackTop = -1;
	pBinaryNode pMove = root;
	while (StackTop != -1 || pMove)
	{
		while (pMove)
		{
			cout << pMove->ch << " ";
			//打印根
			Treestack[++StackTop] = pMove;
			//将打印过的节点丢到栈中
			pMove = pMove->lchild;
			//将根置为左节点
			//此时栈中保存的是已经打印过的节点
		}
		if (StackTop != -1)
		{
			//到这里 左边的节点已经全部输出完，
			//此时pMove是左边叶子节点的下一个节点NULL
			//然后我们往后挪一个节点,置为右边 根左都输出完了
			pMove = Treestack[StackTop];
			StackTop--;
			pMove = pMove->rchild;
		}
	}
}

void CreateBinaryTree()
{
	//创建结点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	NonRecursion(&node1);
}



int main()
{
	CreateBinaryTree();

	system("pause");
	return 0;
}