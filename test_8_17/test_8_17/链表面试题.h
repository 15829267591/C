#pragma once

#include "List.h"
#include <stdio.h>

//��β��ͷ��ӡ
void PrintReverse(ListNode* first)
{
  ListNode * end = NULL;
  while (end != first)
  {
	  ListNode* cur = first;
	  while(cur->next!= end)
	  {
		  cur = cur->next;
	  }
	  printf("%d->", cur->date);
	  end = cur;

  }
}
void TestPrintReverse()
{
	ListNode *first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);

	PrintReverse(first);
}

void PrintResverseRecursion(ListNode* first)
{
	if(first->next ==NULL)
	{
		printf("%d->",first->date);
	}
	else
	{
		PrintResverseRecursion(first->next);
		

	}



}

void TestPrintReverse2()
{
	ListNode *first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);

	PrintReverse(first);
}
//��������
ListNode* ReverseList(ListNode* first)
{
	ListNode* cur = first;
	ListNode* node;
	ListNode* result = NULL;
	while(cur != NULL)
	{
		node = cur;
		cur = cur->next;
		node->next = result;
		result = node;
	}
	return result;
}


void TestResverseList1()
{
	ListNode* first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	ReverseList( first);

}

//��ͷ����Ĳ���ɾ������
void RemoveNoFirst(ListNode* pos)
{
	ListNode* del = NULL;
	pos->date = pos->next->date;
	del = pos->next;
	pos->next = pos->next->next;
	free(del);

}
void InsertNoFirst(ListNode *pos)
{
	//TODO:
}
//Լɪ��

ListNode* JosephCycle(ListNode * first, int k)
{
	//���ɻ�
	ListNode* tail = first;
	ListNode* cur = first;
	ListNode* pre = NULL;

	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	// �ڶ���ɾ�����
	while(cur->next != cur)
	{
		int i = 0;
		for(i=0; i<k-1; i++)
		{
           pre = cur;
		   cur = cur->next;
		}
		//cur����Ҫɾ���Ľ��
		pre->next = cur->next;
		free(cur);
		cur = pre->next;
	}
	cur->next = NULL;
	return cur;
}

void TestJosephCycle()
{
	ListNode *first = NULL;
	ListNode* sur = NULL;
	int i = 0;
	for(i=1; i<8; i++)
	{
		ListPushBack(&first, i);
	}
	 sur = JosephCycle(first, 4);
	printf("%d\n", sur->date);
}
//�ϲ�������������(����)
ListNode* MergeOrder(ListNode* list1, ListNode* list2)
{
	ListNode* cur1 = list1;
	ListNode* cur2 = list2;
	ListNode* tail = NULL;
	ListNode* result = NULL;
	ListNode* next =NULL;
	while(cur1 != NULL && cur2 !=NULL)
	{
		if(cur1->date<=cur2->date)
		{
			//��cur1�����������
			if(result!=NULL)
			{
				next = cur1->next;
				cur1->next = NULL;
				tail->next = cur1;
				tail = cur1;
				cur1 = next;

			}
			else
			{
				next = cur1->next;
				result = cur1;
				cur1->next = NULL;
				tail = cur1;
				cur1 = next;

			}
		}
		else 
		{
			if(result != NULL)
			{
				next = cur2->next;
				cur2->next = NULL;
				tail->next = cur2;
				tail = cur2;
				cur2 = next;
			}
			else
			{
				next = cur2->next;
				result = cur2;
				cur2->next = NULL;
				tail = cur2;
				cur2 = next;
			}

		}
		

	}
	if(cur1 == NULL)
	{
		tail->next = cur2;
	}
	else
	{
		tail->next = cur1;
	}

	return result;
}

ListNode* MergeOrderAd(ListNode* list1, ListNode* list2)
{
	ListNode* cur1 = list1;
	ListNode* cur2 = list2;
	ListNode* tail = NULL;
	ListNode* result = NULL;
	ListNode* next =NULL;
	ListNode* node = NULL;
	while(cur1 != NULL && cur2 !=NULL)
	{
		if(cur1->date<=cur2->date)
		{
			node = cur1;
		}
		else
		{
			node = cur2;
		}
          
		
			//��cur1�����������
			if(result!=NULL)
			{
				tail->next = node;
			}
			else
			{
				result = node;

			}
			next = node->next;
			node->next = NULL;
			tail = node;
			if(node == cur1)
			{
				cur1 = next;
			}
			else
			{
				cur2 = next;
			
			}
		}
	
		

	
	if(cur1 == NULL)
	{
		tail->next = cur2;
	}
	else
		tail->next = cur1;

	return result;
}

void TestMerge()
{
	ListNode * list1 = NULL;
	ListNode*  list2  =NULL;
	ListNode* sur = NULL;
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 15);
	ListPushBack(&list1, 17);
	ListPushBack(&list2, 2);
	ListPushBack(&list2, 5);
	ListPushBack(&list2, 6);
	

    sur = MergeOrder(list1,  list2);
	ListPrint(sur);
}
//�����������������е���ͬ����

void PrintInterSection(ListNode* list1, ListNode* list2)
{
	ListNode* cur1 = list1;
	ListNode* cur2 = list2;
	while(cur1!=NULL && cur2!=NULL)
	{
		if(cur1->date<cur2->date)
		{
			cur1 = cur1->next;
		}
		else if(cur1->date > cur2->date)
		{
			cur2 = cur2->next;
		}
		else
		{
			printf("%d ", cur1->date);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

}

void TestPrintInterSection()
{
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;

	ListPushBack(&list1, 1);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 6);
	ListPushBack(&list1, 7);

	ListPushBack(&list2, 3);
	ListPushBack(&list2, 6);

	PrintInterSection(list1, list2);

}

//���ҵ�������м�ڵ㣨ֻ�ܱ���һ�Σ�
void FindMid(ListNode* first)
{
	ListNode* fast = first;
	ListNode* slow = first;
	while(1)
	{
		//��ʦ������
		//fast = fast->next;
		//if(fast==NULL)
		//{
		//	break;
		//}
		//fast = fast->next;
		//if(fast==NULL)
		//{
		//	break;
		//}
		
		//�Լ��ķ���
		if(fast->next== NULL)
		{
		break;
		}
		else
		{
			fast = fast->next;
		}
		if(fast->next== NULL)
		{
		break;
		}
		else
		{
			fast = fast->next;
		}
		
		slow = slow->next;

	}
	printf("%d ", slow->date);

}

void TestFindMid()
{
	ListNode* first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	FindMid(first);
	ListPushBack(&first, 6);
	FindMid(first);


}
//���ҵ�����ĵ�����k�����
void FindTailK(ListNode* first, int k)
{
	ListNode* forward = first;
	ListNode* backward = first;
	while(k--)
	{
		forward = forward->next;
	}
	while(forward!=NULL)
	{
		forward = forward->next;
		backward = backward->next;
	}
	printf("%d ", backward->date);
}

void TestFindTailK()
{
	ListNode* pfirst = NULL;
	ListPushBack(&pfirst, 1);
	ListPushBack(&pfirst, 2);
	ListPushBack(&pfirst, 3);
	ListPushBack(&pfirst, 4);
	ListPushBack(&pfirst, 5);

	FindTailK(pfirst, 2);
}

//ɾ��������K�����
void FindTailPopK(ListNode* first ,int k)
{
	ListNode* forward = first;
	ListNode* backward = first;
	ListNode* p = NULL;
	while(k--)
	{
		forward = forward->next;
	}
	while(forward!=NULL)
	{
		p = backward;
		forward = forward->next;
		backward = backward->next;
		
		
	}
	p->next= backward->next;
	free(backward);

	
}

void TestFindTailPopk()
{
	ListNode* first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	ListPushBack(&first, 6);

	FindTailPopK(first, 2);
}