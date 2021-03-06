// C++Playground.cpp : Defines the entry point for the console application.
//

#include "WidthOfBinaryTree.h"
#include "LengthOfLongestSubstring.h"
#include "ValidateParenthesis.h"
#include "WidthOfBinaryTree.h"
#include "MergeTwoSortedLists.h"
#include "22. GenerateParenthesis.h"
#include "239. Sliding Window Maximum.h"
#include "424. Longest Repeating Character Replacement.h"
#include "MaxProductFromAnArray.h"
#include "146. LRU Cache.h"
#include "208. Implement Trie (Prefix Tree).h"
#include "200. Number of Islands.h"
#include "230. Kth Smallest Element in a BST.h"
#include "347. Top K Frequent Elements.h"

using namespace std;

#include <stdlib.h>

////C++ stuff
////Rule of 5
//class DummyBaseClass {
//
//private:
//
//	int size = 0;
//	int *pData = nullptr;
//
//	friend void swap(DummyBaseClass& a, DummyBaseClass& b)
//	{
//		std::swap(a.size, b.size);
//		std::swap(a.pData, b.pData);
//
//	}
//
//public:
//
//	DummyBaseClass(int size)
//	{
//		pData = new int[size];
//	}
//
//	DummyBaseClass(DummyBaseClass &obj) :size(obj.size), pData(size ? new int[size] : nullptr)
//	{
//		//std::copy(obj.pData, obj.pData + size, pData);
//	}
//
//	~DummyBaseClass()
//	{
//		delete[] pData;
//	}
//
//	//Use a pass-by-value param instead of reference, because the appropriate copy-constructor would be called to create this temporary argument. 
//	//This avoids the need of writing assignment operator for different types of argument (lval or rVal ref)
//	//more Housekeeping is done by the compiler(calling destructor on the temporary argument object), which is always better
//	DummyBaseClass& operator =(DummyBaseClass obj)
//	{
//		swap(*this, obj);
//		return *this;
//	}
//
//	DummyBaseClass(DummyBaseClass && obj)
//	{
//		swap(*this, obj);
//
//	}
//};
//
//
//static int closestToZero(int ints[], int size) {
//
//	int diff = abs(ints[0]), last = 0;
//	for (int i = 1; i < size; i++)
//	{
//		if (abs(ints[i]) < diff)
//		{
//			diff = abs(ints[i]);
//			last = i;
//		}
//		else if (abs(ints[i]) == diff)
//		{
//			if (ints[last] < ints[i])
//				last = i;
//		}
//
//	}
//
//	return ints[last];
//}
//
//
//////3 ways to define a functor
////
////struct functor {
////
////public:
////
////
////	//less than
////	bool operator()(int&a, int&b)
////	{
////		return a<b;
////	}
////};
//
//
//
//int findKthLargest(vector<int> nums, int k) 
//{
//
//	auto lambda = [](int&a, int&b) {return a < b; };
//	make_heap(nums.begin(), nums.end(), lambda);
//
//	for (int i = 0; i < k; i++)
//	{
//		pop_heap(nums.begin(), nums.end()-i);
//	}
//
//	return *(nums.end()-k);
//
//	//for(int i=0; )
//
//
//}

class Ticket
{
	

public:
	string source;
	string dest;
	Ticket(string src, string dest) :source(src), dest(dest) {}
};

class Result
{
public:
	string begin;
	string end;
};

/*
DC - LDN
RAL - DC
DUB - DEL
LDN - DUB
*/
Result FindBeginAndEnd(const std::list<Ticket>& tickets)
{
	Result ret;
	unordered_map<string, int> map;
	for (Ticket ticket : tickets)
	{
		++map[ticket.source];
		++map[ticket.dest];
	}

	pair<string, string> SrcDest;
	auto itr = map.begin();
	for (; itr != map.end(); itr++)
	{
		if (itr->second == 1)
		{
			if (SrcDest.first == "")
				SrcDest.first = itr->first;
			else if(SrcDest.second == "")
				SrcDest.second = itr->first;
			else
			{
				throw std::exception("Invalid Tickets");
			}

		}
	}

	for (Ticket ticket : tickets)
	{
		if (ticket.source == SrcDest.first)
			ret.begin = SrcDest.first;

		if (ticket.source == SrcDest.second)
			ret.begin = SrcDest.second;

		if (ticket.dest == SrcDest.first)
			ret.end = SrcDest.first;

		if (ticket.dest == SrcDest.second)
			ret.end = SrcDest.second;
	}

	if (ret.begin == "" || ret.end == "")
		throw std::exception("Ivalid Tickets");

	return ret;
}



vector<int> inorderTraversal(TreeNode* root) {


	//if (root)
	//{
	//	inorderTraversal(root->left);
	//}

	return vector<int>();
}


//Result FindBeginAndEnd(const std::list<Ticket>& tickets)

int main()
{
	
	/*
	DC - LDN
	RAL - DC
	DUB - DEL
	LDN - DUB
	*/
	/*list<Ticket> lst;
	lst.push_back(Ticket("DC", "LDN"));
	lst.push_back(Ticket("RAL", "DC"));
	lst.push_back(Ticket("DUB", "DEL"));
	lst.push_back(Ticket("LDN", "DUB"));

	Result res = FindBeginAndEnd(lst);

	cout << res.begin << " " << res.end;*/

	/*Trie t;
	t.insert("");
	t.insert("hello");

	cout<<t.search("hell");
	cout << endl;
	cout << t.search("helloa");
	cout << endl;
	cout << t.search("hello");
	cout << endl;
	cout << t.startsWith("hell");
	cout << endl;
	cout << t.startsWith("helloa");
	cout << endl;
	cout << t.startsWith("hello");
	cout << endl;
	cout << t.search("cat");
	cout << endl;
*/



	//kthSmallestNumber kthSmallestNumber;

	////vector<vector<char>> grid{{'1', '1', '1', '1', '0'},{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'}};
	//vector<vector<char>> grid{ {'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'} };
	//numOfIslands islands;

	//cout<<islands.numIslands(grid);



	vector<int> vec1, vec2, vec3;

	vec1.resize(7, 3);

	//{3,3,3,3,3,3,3}
	//       ↑

	/*auto itr = vec1.begin() + (vec1.size() / 2);

 
	vec2.resize(distance(vec1.begin(), itr));
	vec3.resize(distance(itr+1, vec1.end()));

	swap_ranges(vec1.begin(), itr, vec2.begin());
	swap_ranges(itr+1, vec1.end(), vec3.begin());
*/

	vector<int>vec({ 1,1,1,2,2,3,4,4,4,4,4,5 });
	topKFrequent(vec, 3);
}








