#pragma once
#include <iostream>
using namespace std;

//ctrl shift + U ת���ɴ�д
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE * lchild;
	struct BINARYNODE * rchild;
}BinaryNode, *pBinaryNode;

//�ݹ���� �������
void Recursion(pBinaryNode root)
{
	//�����һ���ڵ���˳�
	if (root == NULL)
		return;
	//���ʸ��ڵ�
	cout << root->ch << " ";
	//�ݹ�������ҽڵ�
	Recursion(root->lchild);
	Recursion(root->rchild);
}
//�������
void a(pBinaryNode root)
{
	if (root == NULL)
		return;
	a(root->lchild);
	cout << root->ch << " ";
	a(root->rchild);
}
//��������
void b(pBinaryNode root)
{
	if (root == NULL)
		return;
	b(root->lchild);	
	b(root->rchild);
	cout << root->ch << " ";
}

//��Ҷ����
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
//��������߶�
int TreeHeight(pBinaryNode root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		// �����������ĸ߶Ⱥ��������ĸ߶� 
		int lHeight = TreeHeight(root->lchild);
		int rHeight = TreeHeight(root->rchild);
		// ���ض��߽ϴ��߼�1 
		if (lHeight > rHeight)
			return(lHeight + 1);
		else return(rHeight + 1);
	}
}
//����������
pBinaryNode CopyBinaryTree(pBinaryNode root)
{
	if (root == NULL)
		return NULL;
	//�������ҽڵ�
	pBinaryNode lchild = CopyBinaryTree(root->lchild);
	pBinaryNode rchild = CopyBinaryTree(root->rchild);

	pBinaryNode newnode = new BinaryNode();
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}
//�ͷ�
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
	//�������
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };
	//��������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	int lefNum = 0;
	CaculateLeafNum(&node1, &lefNum);
	cout << "Ҷ�ӽڵ������" << lefNum  << endl;


	cout << TreeHeight(&node1) << endl;
	//�ݹ����
	cout << "�������:";
	Recursion(&node1);
	cout << endl;

	cout << "�������:";
	a(&node1);
	cout << endl;

	cout << "�������:";
	b(&node1);
	cout << endl;


	pBinaryNode root = CopyBinaryTree(&node1);
	cout << "root���������:";
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