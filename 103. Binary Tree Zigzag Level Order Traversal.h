#pragma once
#include "Header.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	vector<vector<int>> ret;

	deque<TreeNode*> q1, q2;
	bool even = true;
	q1.push_front(root);
	while (q1.size())
	{
		swap(q1, q2);
		vector<int> vec;
		while (q2.size())
		{
			TreeNode* node;

			node = q2.back();
			q2.pop_back();

			if (node)
			{
				vec.push_back(node->val);
				if (!even)
				{
					q1.push_back(node->right);
					q1.push_back(node->left);
				}
				else
				{
					q1.push_back(node->left);
					q1.push_back(node->right);
				}
			}
		}
		
		even = !even;

		if (vec.size())
			ret.push_back(vec);
	}

	return ret;
}
