#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct BTreeNode
{
	int data;
	struct BTreeNode* left;
	struct BTreeNdoe* right;
} BTreeNode;

BTreeNode* CreateNode(int data)
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
		return node;
}

BTreeNode* CreateTree(int preOrder[], int InOrder[], int size)
{
    int i = 0;
	int rootInOrder = -1;
	BTreeNode* node = NULL;
	BTreeNode* root = NULL;
	
	int rootValue = preOrder[0];
    
	for(i=0; i<size; i++)
	{
		if(InOrder[i]==rootValue)
			rootInOrder = 1;

	}
	assert(rootInOrder!=-1);
	node = CreateNode(rootValue);

	//Ç°Ðò ×ó×ÓÊ÷ [1,preOrder +Ino) 

	root = CreateNode(rootValue);
	root->left = CreateTree(preOrder+1,InOrder, rootInOrder);
	root->right = CreateTree(preOrder+rootInOrder+1,InOrder+1+rootInOrder,size - 1 - rootInOrder);

	return root;
}

void Test()
{
	int preOrder[] = { 1, 2, 3, 4, 5, 6, 7 };
	int inOrder[] = { 2, 1, 4, 6, 7, 5, 3 };
	int size = sizeof(preOrder) / sizeof(int);

	BTreeNode *root = CreateTree(preOrder, inOrder, size);


	printf("success\n");
}