#pragma once
#include <iostream>
using namespace std;

//ctrl shift + U 转换成大写
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE * lchild;
	struct BINARYNODE * rchild;
}BinaryNode, *pBinaryNode;

//递归遍历 先序遍历
void Recursion(pBinaryNode root)
{
	//到最后一个节点就退出
	if (root == NULL)
		return;
	//访问根节点
	cout << root->ch << " ";
	//递归访问左右节点
	Recursion(root->lchild);
	Recursion(root->rchild);
}
//中序遍历
void a(pBinaryNode root)
{
	if (root == NULL)
		return;
	a(root->lchild);
	cout << root->ch << " ";
	a(root->rchild);
}
//后续遍历
void b(pBinaryNode root)
{
	if (root == NULL)
		return;
	b(root->lchild);	
	b(root->rchild);
	cout << root->ch << " ";
}

//求叶子树
void CaculateLeafNum(pBinaryNode root, int * lefNum)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*lefNum)++;
	}
	CaculateLeafNum(root->lchild, lefNum);
	CaculateLeafNum(root->rchild, lefNum);
}
//求二叉树高度
int TreeHeight(pBinaryNode root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		// 计算左子树的高度和右子树的高度 
		int lHeight = TreeHeight(root->lchild);
		int rHeight = TreeHeight(root->rchild);
		// 返回二者较大者加1 
		if (lHeight > rHeight)
			return(lHeight + 1);
		else return(rHeight + 1);
	}
}
//拷贝二叉树
pBinaryNode CopyBinaryTree(pBinaryNode root)
{
	if (root == NULL)
		return NULL;
	//拷贝左右节点
	pBinaryNode lchild = CopyBinaryTree(root->lchild);
	pBinaryNode rchild = CopyBinaryTree(root->rchild);

	pBinaryNode newnode = new BinaryNode();
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}
//释放
void freeBinaryTree(pBinaryNode root)
{
	if (root == NULL)
		return;
	freeBinaryTree(root->lchild);
	freeBinaryTree(root->rchild);
	delete root;
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

	int lefNum = 0;
	CaculateLeafNum(&node1, &lefNum);
	cout << "叶子节点的数量" << lefNum  << endl;


	cout << TreeHeight(&node1) << endl;
	//递归遍历
	cout << "先序遍历:";
	Recursion(&node1);
	cout << endl;

	cout << "中序遍历:";
	a(&node1);
	cout << endl;

	cout << "后序遍历:";
	b(&node1);
	cout << endl;


	pBinaryNode root = CopyBinaryTree(&node1);
	cout << "root的先序遍历:";
	Recursion(root);
	cout << endl;
	freeBinaryTree(root);
}



int main()
{
	CreateBinaryTree();
	
	system("pause");
	return 0;
}