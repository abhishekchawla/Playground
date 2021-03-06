#pragma once

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>   
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <memory>
#include <deque>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct GraphNode:public enable_shared_from_this<GraphNode> {

	int val;
	vector<shared_ptr<GraphNode>> neighbours;
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {

	string res;
	if (!root)
		return res;

	queue<TreeNode*> q;
	q.push(root);
	while (q.size())
	{
		TreeNode* node = q.front();
		q.pop();

		if (node)
		{
			res += to_string(node->val) + ",";
			q.push(node->left);
			q.push(node->right);
		}
		else
			res += "#,";
	}

	return res;
}

// Decodes your encoded data to tree
//string has to be in this format "1,2,#,3,4" 
TreeNode* deserialize(string data) {

	TreeNode* root = nullptr;
	if (!data.size() || data[0] == '#')
		return root;

	istringstream iss(data);
	string val;
	getline(iss, val, ',');
	root = new TreeNode(stoi(val));
	queue<TreeNode*> q; q.push(root);

	while (q.size())
	{

		if (iss.eof())
			break;

		TreeNode* node = q.front();
		q.pop();

		if (!node)
			continue;

		getline(iss, val, ',');
		if (val != "#")
		{
			node->left = new TreeNode(stoi(val));
			q.push(node->left);
		}
		else
			q.push(nullptr);

		getline(iss, val, ',');
		if (val != "#")
		{
			node->right = new TreeNode(stoi(val));
			q.push(node->right);
		}
		else
			q.push(nullptr);
	}

	return root;
}
