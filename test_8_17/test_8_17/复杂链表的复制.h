#pragma once

#include <stdlib.h>
#include <assert.h>

typedef struct CLNode
{
	int data;
	struct CLNode* random;
	struct CLNode* next;
} CLNode;
static CLNode* ComplexCreateNode(int data)
{
	CLNode* node = (CLNode*)malloc(sizeof(CLNode));
	node->data = data;
	node->next = NULL;
	node->random = NULL;
	return node;
}
CLNode* Copy(CLNode* list)
{
	CLNode* newlist = NULL;
	CLNode* node = NULL;
	CLNode* cur  = NULL;
	//1.复制结点
	 cur = list;
	while(cur != NULL)
	{
		CLNode* newnode = ComplexCreateNode(cur->data);
		newnode->next = cur->next;
		cur = cur->next->next;

	}
	//2.复制random
	cur = list;
	while(cur!=NULL)
	{
		if(cur->random!=NULL)
		{
          cur->next->random = cur->random->next;
		}
		//else
		//	cur->next->random = NULL;
		cur = cur->next->next;
		
	}
	//3.拆分
	cur = list;
	
	
    newlist = cur->next;
	node = NULL;
	while(cur!=NULL)
	{
		node = cur->next;
		cur->next = node->next;
		if(cur->next !=NULL)
		{
			node->next = cur->next->next;
		}
		else
		{
			node->next = NULL;
		}
		cur = cur->next;
	}
	return newlist;
}

void PrintComplexList(CLNode* list)
{
	CLNode* cur = NULL;
	for(cur=list; cur!=NULL; cur= cur->next)
	{
		printf("[%d, random(%p)->%d]", cur->data,cur->random,cur->random?cur->random->data:0);
	}
	printf("\n");
}

void TestComplex()
{
	CLNode* newlist = NULL;
	CLNode* n1 = ComplexCreateNode(1);
	CLNode* n2 = ComplexCreateNode(2);
	CLNode* n3 = ComplexCreateNode(3);
	CLNode* n4 = ComplexCreateNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	n4->random = NULL;

	 newlist = Copy(n1);
	PrintComplexList(n1);
	PrintComplexList(newlist);

}
