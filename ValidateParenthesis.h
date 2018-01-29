#pragma once

#include "Header.h"

/*20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool isValid(string s) {

	stack<char> stk;

	for (char c : s)
	{
		if (c == '(' || c == '[' || c == '{')
			stk.push(c);
		else if (c == ')')
		{
			if (stk.size() && stk.top() == '(')
				stk.pop();
			else
				return false;
		}
		else if (c == ']')
		{
			if (stk.size() && stk.top() == '[')
				stk.pop();
			else
				return false;
		}
		else if (c == '}')
			if (stk.size() && stk.top() == '{')
				stk.pop();
			else
				return false;
	}

	if (!stk.size())
		return true;
	else
		return false;
}