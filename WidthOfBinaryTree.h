#pragma once

#include "Header.h"

int widthOfBinaryTree(TreeNode* root) {

	if (!root)
		return 0;

	int maxWidth = 1;

	queue<pair<TreeNode*, int>> q1;
	q1.push({ root, 1 });
	while (q1.size())
	{
		int l = 0, r = 0;

		queue<pair<TreeNode*, int>> q2;
		std::swap(q1, q2);

		while (q2.size())
		{
			auto node = q2.front();
			q2.pop();
			if (node.first)
			{
				r = node.second;
				if (l == 0)l = r;
				q1.push({ node.first->left, r * 2 });
				q1.push({ node.first->right, r * 2 + 1 });
			}
		}

		maxWidth = max(maxWidth, r - l + 1);

	}

	return maxWidth;
}


