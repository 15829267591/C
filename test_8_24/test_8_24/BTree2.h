//
//#pragma once
//
//#include <stdlib.h>
//#include <assert.h>
//#include <stdio.h>
//#include "Queue.h"
//
//typedef int TDataType;
//typedef struct BTreeNode
//{
//	TDataType data;
//	struct BTreeNode* left;
//	struct BTreeNode* right;
//
//}BTreeNode;
//
//BTreeNode* CreateNode(int data)
//{
//	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
//	node->data = data;
//	node->left = node->right =NULL;
//	return node;
//}
//
//BTreeNode* CreateTree(int preOrder[], int size, int* useSize)
//{
//	int rootValue = preOrder[0];
//	int leftUse;
//	int rightUse; 
//	BTreeNode* root = CreateNode(rootValue);
//	 if(size<=0)
//	 {
//		 *useSize = 0;
//		 return NULL;
//
//	 }
//
//	 if(rootValue==-1)
//	 {
//		 *useSize = 1;
//		 return NULL;
//	 }
//
//	 root->left = CreateTree(preOrder+1, size-1, &leftUse);
//	 root->right = CreateTree(preOrder+1+leftUse, size-1-leftUse, &rightUse);
//	 *useSize = 1+leftUse+rightUse;
//	 return root;
//}
//
////void PreOrderLoop(BTreeNode* root)
////{
////	Stack stack;
////	
////	BTreeNode* cur;
////	BTreeNode* top;
////    StackInit(&stack);
////	cur = root;
////	while (cur!=NULL||!StackEmpty(&stack))
////	{
////		while(cur!=NULL)
////		{
////			printf("%d ", cur->data);
////			
////			StackPush(&stack, cur);
////            cur = cur->left;
////		}
////
////		top = StackTop(&stack);
////		StackPop(&stack);
////
////		cur = top->right;
////	}
////	
////}
//
////void InOrderLoop(BreeeNode* root)
////{
////	Stack stack;
////	StackInit(&stack);
////	BTreeNode* cur;
////	BTreeNode* top;
////	cur = root;
////	while(cur!=NULL||!StackEmpty(&stack))
////	{
////		while(cur!=NULL)
////		{
////			StackPush(&stack, cur);
////			cur = cur->left;
////		}
////		top = StackTop(&stack);
////		StackPop(&stack);
////		printf("%d ",cur->data);
////		cur = top->right;
////	}
////}
//
////void PostOrderLoop(BTreeNode* root)
////{
////	Stack stack;
////	BTreeNode* cur;
////	BTreeNode* top;
////	BTreeNode* last = NULL;
////	StackInit(&stack);
////	cur = root;
////	while(cur!=NULL||!StackEmpty(&stack))
////	{
////		while(cur!=NULL)
////		{
////			StackPUush(&stack, cur);
////			cur = cur->left;
////		}
////		    top = StackTop(&stack);
////		if(cur->right==NULL||cur->right==last)
////		{
////			printf("%d ", cur->data);
////			StackPop(&stack);
////		    last=top;
////	     	
////		}
////		else
////		{
////			cur = top->right;
////		}
////
////		
////	}
////}
//
//BTreeNode* Find(BTreeNode* root, TDataType data)
//{
//	BTreeNode* result =NULL;
//	if(root==NULL);
//	{
//		return NULL;
//	}
//	if(root->data = data)
//	{
//		return root;
//	}
//	result = Find(root->left, data);
//	if(result!=NULL)
//	{
//		return result;
//	}
//	result = Find(root->right, data);
//    if(result!=NULL)
//	{
//		return result;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
////找祖先结点
//BTreeNode* GetAncestor(BTreeNode* root, BTreeNode* node1,BTreeNode* node2)
//{
//	BTreeNode* node1InLeft = Find(root->left, node1->data);
//	BTreeNode* node1InRight = Find(root->right, node1->data);
//	BTreeNode* node2InLeft = Find(root->left, node2->data);
//	BTreeNode* node2InRight = Find(root->right,node2->data);
//
//	if((node1InLeft&&node2InRight)||(node2InLeft&&node1InRight))
//	{
//        return root;
//	}
//	if(node1InLeft)
//	{
//		return GetAncestor(root->left,node1,node2);
//	}
//	else
//	{
//		return GetAncestor(root->right,node1,node2);
//	}
//
//}
//#define MAX(a, b)	((a) > (b) ? (a) : (b))
//int GetHeight(BTreeNode *root)
//{
//	if (root == NULL) 
//	{
//		return 0;
//	}
//
//	// 当子树只有一个结点的时候，可以写，也可以不写
//	// 写的话，节省两次函数调用
//
//	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
//}
//
//int IsBalance(BTreeNode* root)
//{
//	int leftBalance = 0;
//	int rightBalance = 0;
//    int left = 0;
//    int right = 0;
//	int p =0;
//
//	if(root==NULL)
//	{
//		return 1;
//	}
//   leftBalance = IsBalance(root->left);
//	if(!leftBalance)
//	{
//		return 0;
//	}
//	 rightBalance = IsBalance(root->right);
//	if(!rightBalance)
//	{
//		return 0;
//	}
//	 left = GetHeight(root->left);
//	 right = GetHeight(root->right);
//	 p = left-right;
//	if(p>=-1 && p<=1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//
//
//void Test()
//{
//     //int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
//	int preOrder[] = { 1, 2, -1, -1, 3 };
//	int size = sizeof(preOrder) / sizeof(int);
//	int usedSize;
//
//	BTreeNode *root = CreateTree(preOrder, size, &usedSize);
//
//	printf("%d\n", IsBalance(root));
//	
//}




















