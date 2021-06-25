#include <iostream>
using namespace std;

//�жϻ��� NC141
bool judge(string str) {
	// write code here
	int a = str.length();
	int start = 0;
	int end = a - 1;
	while (start < end)
	{
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}
	return true;
}

//�ж��Ƿ���һ��ƽ�� NC62
/*
����һ�ö��������жϸö������Ƿ���ƽ���������
���������ֻ��Ҫ������ƽ���ԣ�����Ҫ�������ǲ������������
ƽ���������Balanced Binary Tree���������������ʣ�����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ���������
*/
int treeHeight(TreeNode* pRoot)
{
	//�ó����ĸ߶�
	if (pRoot == NULL)
		return 0;
	int left = treeHeight(pRoot->left);
	int right = treeHeight(pRoot->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL)
		return true;
	//�ж��Ƿ����
	int left = treeHeight(pRoot->left);
	int right = treeHeight(pRoot->right);
	int gap = left - right;
	if (gap > 1 || gap < -1)
		return false;
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}