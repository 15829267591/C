#include "List.h"
#include <stdio.h>

//ÄæÐò´òÓ¡
void PrintReverse(ListNode* first)
{
	ListNode* end = NULL;
	ListNode* cur = NULL;
	while(end!=first)
	{
        cur = first;
	}
	while(cur->next != NULL)
	{
      cur = cur->next;
	}
	printf("%d\n", cur->date);

	end = cur;

}
void TestPrintReverse()

{
	ListNode* first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	PrintReverse(first);
}
ListNode* ReverseList(ListNode* first)
{
	ListNode* cur = first;
	ListNode* result = NULL;
	ListNode* node;
	while(cur!=NULL)
	{
		node = cur;
		cur = cur->next;
		node->next = result;
		result = node;
	}
	return result;
}

void TestReverseList()
{
	 ListNode* first ;
     ListPushBack(&first, 1);
	 ListPushBack(&first, 2);
	 ListPushBack(&first, 3);
     ListPushBack(&first, 5);
	 
}
void RemoveNoFirst(ListNode* pos)
{
	ListNode* del;
	pos->date = pos->next ->date ;
	pos->next = pos->next ->next ;
	free(del);
}

void InsertNoFirst(ListNode* pos, DateType date)
{
    ListNode* newNode=CreateNode(date);
	assert(newNode != NULL);
	pos->date = pos->next ->date ;
	pos->next = pos->next ->next ;
}
