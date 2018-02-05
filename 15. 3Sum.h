#pragma once
#include "Header.h"
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]*/
vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> ret;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
		{
			int target = -nums[i];
			int front = i + 1, back = nums.size() - 1;

			while (front < back)
			{
				int sum = nums[front] + nums[back];

				if (sum < target)
					++front;
				else if (sum > target)
					--back;
				else
				{
					ret.push_back({ nums[i], nums[front], nums[back] });
					int frontVal = nums[front], backVal = nums[back];
					while (nums[front] == frontVal && front < back)
						++front;
					while (nums[back] == backVal && front < back)
						--back;
				}

			}
		}

	}

	return ret;
}