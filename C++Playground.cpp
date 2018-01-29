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

using namespace std;

#include <stdlib.h>

//C++ stuff
//Rule of 5
class DummyBaseClass {

private:

	int size = 0;
	int *pData = nullptr;

	friend void swap(DummyBaseClass& a, DummyBaseClass& b)
	{
		std::swap(a.size, b.size);
		std::swap(a.pData, b.pData);

	}
public:

	DummyBaseClass(int size)
	{
		pData = new int[size];
	}

	DummyBaseClass(DummyBaseClass &obj) :size(obj.size), pData(size ? new int[size] : nullptr)
	{
		//std::copy(obj.pData, obj.pData + size, pData);
	}

	~DummyBaseClass()
	{
		delete[] pData;
	}

	//Use a pass-by-value param instead of reference, because the appropriate copy-constructor would be called to create this temporary argument. 
	//This avoids the need of writing assignment operator for different types of argument (lval or rVal ref)
	//more Housekeeping is done by the compiler(calling destructor on the temporary argument object), which is always better
	DummyBaseClass& operator =(DummyBaseClass obj)
	{
		swap(*this, obj);
		return *this;
	}

	DummyBaseClass(DummyBaseClass && obj)
	{
		swap(*this, obj);

	}
};


static int closestToZero(int ints[], int size) {

	int diff = abs(ints[0]), last = 0;
	for (int i = 1; i < size; i++)
	{
		if (abs(ints[i]) < diff)
		{
			diff = abs(ints[i]);
			last = i;
		}
		else if (abs(ints[i]) == diff)
		{
			if (ints[last] < ints[i])
				last = i;
		}

	}

	return ints[last];
}

int main()
{

}

