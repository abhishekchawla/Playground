#include "Header.h"

/*3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

int lengthOfLongestSubstring(string s) {

	if (!s.size())
		return 0;

	int ret = 1;
	unordered_map<char, int>  mapPosition;
	int start = 0;
	int i = 0;
	for (; i < s.size(); i++)
	{
		if (mapPosition.find(s[i])!=mapPosition.end() && mapPosition[s[i]] >= start)
		{
			ret = max(ret, i - start);
			start = mapPosition[s[i]] + 1;
		}

		mapPosition[s[i]] = i;
	}
	
	ret = max(ret, i - start);

	return ret;
}


//This function returs the substring that has non repeating letters
string LongestNonRepSubstring(string &s)
{
	unordered_map<char, int> mapChars;

	if (!s.size())
		return "";

	int start = 0, len = 1, actualPos = 0;
	for (int i = 0; i < s.size(); i++)
	{
		auto itr = mapChars.find(s[i]);
		if (itr != mapChars.end() && itr->second > start)
		{
			if (len < i - start + 1)
			{
				len = i - start + 1;
				actualPos = start;
			}
			start = itr->second + 1;
		}
		mapChars[s[i]] = i;
	}

	return s.substr(actualPos, len);
}