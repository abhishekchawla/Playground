#pragma once
#include "Header.h"

//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return :
//
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//Note: All inputs will be in lower - case.

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	vector<vector<string>> ret;
	unordered_map<string, vector<string>> umap;
	for (string str : strs)
	{
		string s = str;
		sort(s.begin(), s.end());
		umap[s].push_back(move(str));
	}
	for (auto itr : umap)
		ret.push_back(move(itr.second));
	return ret;



}