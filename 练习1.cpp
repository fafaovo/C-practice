#include <iostream>
using namespace std;

//判断回文 NC141
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

//判断是否是一颗平衡 NC62
/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
*/
int treeHeight(TreeNode* pRoot)
{
	//得出树的高度
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
	//判断是否空树
	int left = treeHeight(pRoot->left);
	int right = treeHeight(pRoot->right);
	int gap = left - right;
	if (gap > 1 || gap < -1)
		return false;
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}