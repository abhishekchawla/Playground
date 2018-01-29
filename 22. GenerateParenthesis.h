#include "Header.h"

/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

For example, given n = 3, a solution set is :

[
	"((()))",
	"(()())",
	"(())()",
	"()(())",
	"()()()"
]*/


void generateParenthesisHelper(int lCount, int rCount, vector<string> &ret, string strParen)
{
	if (lCount > rCount || lCount <0 || rCount <0)
		return;

	if (lCount == 0 && rCount == 0)
	{
		ret.push_back(strParen);
		return;
	}

	if (lCount)
		generateParenthesisHelper(lCount - 1, rCount, ret, strParen + "(");
	if (rCount)
		generateParenthesisHelper(lCount, rCount - 1, ret, strParen + ")");

}

vector<string> generateParenthesis(int n) {

	vector<string> ret;

	if (n == 0)
		return ret;

	int lCount = n, rCount = n;

	generateParenthesisHelper(n - 1, n, ret, "(");

	return ret;
}