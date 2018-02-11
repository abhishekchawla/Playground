#pragma once
#include "Header.h"
/*
	Given preorder and inorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.

	For example, given

	preorder = [3,9,20,15,7]
	inorder = [9,3,15,20,7]
	Return the following binary tree:

		 3
		/ \
	   9  20
		 /  \
		15   7
*/

TreeNode* buildTreeHelper(int preIdx, int iStart, int iEnd, vector<int>& preorder, vector<int>& inorder)
{
	//Sanity check
	if (!(preIdx < preorder.size()) || !(iStart < iEnd))
		return nullptr;

	TreeNode* node = new TreeNode(preorder[preIdx]);

	int Idx = 0;
	for (Idx = iStart; Idx < iEnd; Idx++)
	{
		if (inorder[Idx] == preorder[preIdx])
			break;
	}

	node->left = buildTreeHelper(preIdx + 1, iStart, Idx, preorder, inorder);
	node->right = buildTreeHelper(preIdx + 1 + Idx - iStart, Idx + 1, iEnd, preorder, inorder);

	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return buildTreeHelper(0, 0, inorder.size(), preorder, inorder);
}