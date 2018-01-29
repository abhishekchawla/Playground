#include "Header.h"

/*34. Search for a Range

	Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

	Your algorithm's runtime complexity must be in the order of O(log n).

	If the target is not found in the array, return [-1, -1].

	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].

*/

vector<int> searchRange(vector<int>& nums, int target) {

	vector<int> ret{ -1, -1 };

	if (!nums.size())
		return ret;

	auto itr = lower_bound(nums.begin(), nums.end(), target);
	if (itr == nums.end() || *itr != target)
		return ret;

	ret.clear();

	ret.push_back((itr - nums.begin()));

	itr = upper_bound(nums.begin(), nums.end(), target);
	--itr;
	ret.push_back((itr - nums.begin()));

	return ret;

}