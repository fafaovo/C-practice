#include <iostream>
using namespace std;


typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE * lchild;
	struct BINARYNODE * rchild;
}BinaryNode, *pBinaryNode;

//�������ķǵݹ����
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
			//��ӡ��
			Treestack[++StackTop] = pMove;
			//����ӡ���Ľڵ㶪��ջ��
			pMove = pMove->lchild;
			//������Ϊ��ڵ�
			//��ʱջ�б�������Ѿ���ӡ���Ľڵ�
		}
		if (StackTop != -1)
		{
			//������ ��ߵĽڵ��Ѿ�ȫ������꣬
			//��ʱpMove�����Ҷ�ӽڵ����һ���ڵ�NULL
			//Ȼ����������Ųһ���ڵ�,��Ϊ�ұ� �����������
			pMove = Treestack[StackTop];
			StackTop--;
			pMove = pMove->rchild;
		}
	}
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

	NonRecursion(&node1);
}



int main()
{
	CreateBinaryTree();

	system("pause");
	return 0;
}