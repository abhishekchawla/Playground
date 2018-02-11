#pragma once
#include "Header.h"
/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

class kthSmallestNumber
{
private:

	void kthSmallestHelper(TreeNode* root, int&k, int& val)
	{
		if (root)
		{
			kthSmallestHelper(root->left, k, val);
			if (k == -1) //kth smallest value has been found, no need to look further
				return;
			else if (k == 1)
			{
				k = -1;
				val = root->val;
				return;
			}
			else
				kthSmallestHelper(root->right, --k, val);
		}
	}

public:

	int kthSmallest(TreeNode* root, int& k)
	{
		int retVal;
		kthSmallestHelper(root, k, retVal);
		return retVal;
	}

	int kthSmallest_itr(TreeNode* root, int k)
	{
		if (!root)
			return -1;

		stack<TreeNode*> stk;
		stk.push(root);
		while (stk.size())
		{
			root = stk.top();
			if (root)
				stk.push(root->left);
			else
			{
				stk.pop();
				if (stk.size())
				{
					root = stk.top();
					//evaluate
					if (k == 1)
						return root->val;
					else
						--k;

					stk.push(root->right);
				}
			}
		}
	}
};
