#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DateType;
typedef struct ListNode{
	DateType date;
	struct ListNode *next;

}ListNode;
void ListInit(ListNode** ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}
void ListDestroy(ListNode**ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}
//�������
static ListNode* CreateNode(DateType date)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode != NULL);
	newNode->date = date;
    newNode->next = NULL;
	return newNode;
}
void ListPushFront(ListNode** ppfirst,DateType date)
{	
	ListNode* newNode = CreateNode(date);
    assert(ppfirst != NULL);
	*ppfirst =NULL;


	newNode->next = *ppfirst;
	*ppfirst = newNode;

}

void ListPushBack(ListNode**ppfirst, DateType date)
{
	ListNode* newNode = CreateNode(date);
	ListNode* cur = NULL;

	if(*ppfirst == NULL)
	{
		*ppfirst = newNode;
	    return;
	}
	
	

		 cur = *ppfirst;
	     while(cur->next != NULL)
	  {
		cur = cur->next;
	  }
	     cur->next = newNode;
	  

}
void ListPopFront(ListNode** ppfirst)
{
	ListNode* del = *ppfirst;
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);
	
	*ppfirst = del->next;
	free(del);
	
}

void ListPopBack(ListNode** ppfirst)
{
	ListNode* del;
	ListNode* cur = *ppfirst;
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);

	if((*ppfirst)->next ==NULL)
	{
        free(*ppfirst);
		*ppfirst = NULL;
		return;
	}
	
	
	while(cur->next->next= NULL)
	{
		cur = cur->next;
	}
	del = cur->next;
	cur->next = NULL;
	free(del);

}
//����
ListNode* ListFind(ListNode* first,DateType date)
{   ListNode* cur =first; 
   for( cur = first; cur!= NULL; cur = cur->next)
  {
	  if(date==cur->date)
	  {
		  return cur;
	  }
  }
  return NULL;

}
//����
void ListInsert(ListNode** ppfirst,ListNode* pos, DateType date)
{  
	ListNode* newNode = CreateNode(date);
	ListNode* cur = *ppfirst;
   assert(ppfirst != NULL);
   assert(pos !=NULL);
   //���������ͷ����������
   if(*ppfirst == pos)
   {
	   ListPushFront(ppfirst,date);
	   return;
   }
   
   while(cur->next != pos)
   {
       cur = cur->next;
   }
   
   assert(newNode!=NULL);
   newNode->next = cur->next;
   cur->next = newNode;
}

//ɾ����ͬ����Ϊͷɾ������ɾ
void ListErase(ListNode** ppfirst, ListNode* pos)
{
	ListNode* cur = *ppfirst;
   assert(ppfirst != NULL);
   if(*ppfirst == pos)
   {
     ListPopFront(ppfirst);
     return;
   }
   
   while(cur->next != pos)
   {
	   cur = cur->next;
   }
   cur->next = pos->next;
   free(pos);
}

void ListPrint(ListNode*first)
	{
		ListNode* cur = first;
		assert( first !=NULL);

        for( cur=first; cur!=NULL ;cur=cur->next)
		{
			printf("%d-> ",  cur->date);
		}
		printf("\n");

	}
void test()
{
	ListNode* first;
	ListNode* result;
	ListInit(&first);//����ַ����Ϊ��һ��Ҫ��
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	result = ListFind(first, 2);//��ֵ��
    ListInsert(&first, result, 0);

}
