#pragma once

#include "Header.h"

/*Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times.Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1 :

	Input :
	s = "ABAB", k = 2

	Output :
	4

	Explanation :
	Replace the two 'A's with two 'B's or vice versa.
	Example 2 :

	Input :
	s = "AABABBA", k = 1

	Output :
	4

	Explanation :
	Replace the one 'A' in the middle with 'B' and form "AABBBBA".
	The substring "BBBB" has the longest repeating letters, which is 4.*/

//this version returns the maximum length of the substring, O(n)
int characterReplacement(string s, int k) {

	if (!s.size())
		return 0;

	//this is an indicator of the maximum window/substring
	int maxCount = 0;

	int start = 0;
	vector<int> count(26, 0);

	int maxLength = 1;
	for (int i = 0; i < s.size(); i++)
	{
		maxCount = max(maxCount, ++count[s[i] - 'A']);

		//if the new substring can accomodate k changes, then check if it is greater than the current max substring
		if (i - start + 1 - maxCount <= k)
			maxLength = max(maxLength, i - start + 1);
		else // move the the maximum-length-window-yet by 1 step
			--count[s[start++] - 'A'];

	}

	return maxLength;
}

//this method returns the substring, O(n)
string characterReplacement_str(string s, int k) {

	int ret;

	//this is an indicator of the maximum window/substring
	int maxCount = 0;

	int trueStart = 0, start = 0;
	vector<int> count(26, 0);

	int maxLength = 1;
	for (int i = 0; i < s.size(); i++)
	{
		maxCount = max(maxCount, ++count[s[i] - 'A']);

		if (i - start + 1 - maxCount <= k)
		{
			if (i - start + 1 > maxLength)
			{
				trueStart = start;
				maxLength = i - start + 1;
			}
		}
		else
			--count[s[start++] - 'A'];
	}

	return s.substr(trueStart, maxLength);
}

