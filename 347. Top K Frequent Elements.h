#pragma once
#include "Header.h"


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
