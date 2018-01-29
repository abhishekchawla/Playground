#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode* ret = new ListNode(0);
	ListNode* start = ret;

	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			ret->next = l1;
			l1 = l1->next;
		}
		else
		{
			ret->next = l2;
			l2 = l2->next;
		}

		ret = ret->next;
	}
	if (l1)
		ret->next = l1;
	else if (l2)
		ret->next = l2;

	ret = start->next;;
	delete start;

	return ret;
}