#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef  int TDataType;

typedef struct BTreeNode
{
  TDataType data;
  strcut BTreeNode* left;
  struct BTreeNode* right;

}BTreeNode

BTreeNode* CreateNode(TDataType data)
{
	BTreeNode* newnode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newnode->data = data;
	newnode->left = newnode->right =NULL;

	return newnode;
}

BTreeNode* CreatTree(int preOrder[], int size, int*pUsesize )
{
    if(szie<0)
	{
		pUseize = 0;
		return NULL;
	}
	BTreeNode* left;
}