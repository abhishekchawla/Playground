#pragma once
#include "Header.h"

/*Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

vector<int> topKFrequent(vector<int>& nums, int k)
{
	vector<int> ret;
	unordered_map<int, int> umap;
	
	for (int i : nums)
		++umap[i];

	auto lmbda = [](pair<int, int> &itr1, pair<int, int> &itr2) {return itr1.second < itr2.second; };

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lmbda)> pq(umap.begin(), umap.end(), lmbda);

	for (int i = 0; i < k; i++)
	{
		ret.push_back(pq.top().first);
		pq.pop();
	}

	return vector<int>();
}
