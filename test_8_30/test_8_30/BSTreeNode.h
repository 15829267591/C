#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct  BSTreeNode
{
	DataType key;
	struct BSTreeNode *left;
	struct BSTreeNode* right;

}BSTreeNode;

//查找
//递归形式

	int BSTreeFind(BSTreeNode* root, DataType key)
	{
	if(root ==NULL)
	{
		return 0;
	}
    if(key == root->key)
	{
		return 1;
	}
	else if(key>root->key)
	{
		return BSTreeFind(root->right, key);
	}
	else 
	{
		return BSTreeFind(root->left, key);
	}
	}

	////非递归



//插入（非递归）
int BSTreeInsert(BSTreeNode** root, DataType key)
{

	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	while(cur!=NULL)
	{
		if(key==cur->key)
		{
			return 0;//重复
		}
		parent = cur;
		if(key>cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}

	}

		
		node->key = key;
		node->left = node->right =NULL;

	if(parent==NULL)
	{
		*root = node;
		return 1;
	}
	if(key<parent->key)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
	return 1;

}
//递归
int BSTreeInsert2(BSTreeNode** root, DataType key)
{
	if(*root==NULL)
	{
		BSTreeNode* node =(BSTreeNode*)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = node->left =NULL;
		*root=node;
		return 1;
	}
	if(key == (*root)->key)
	{
		return 0;
	}
	if(key < (*root)->key)
	{
		return BSTreeInsert2(&(*root)->left, key);
	}
	else
	{
		return BSTreeInsert2(&(*root)->right, key);
	}
}

//删除

static void RemoveLeftNull(DataType key, BSTreeNdoe* parent, BSTreeNode** root, BSTreeNode* cur)
{

		if(parent==NULL)
		 {
			*root = cur->right;
		 }
		else 
		{
			if(key < parent->key)

		  {
			  parent->left = cur->right;
		  }

		else(parent ->right)
		  {
			parent->right = cur->left;
		  }
		}
		free(cur);

	}

static void RemoveRightNull(DataType key, BSTreeNode** root, BSTreeNode*parent, BSTreeNode* cur)
{
	if(parent==NULL)
	{
		*root = cur->right;
	}
	else
	{
		if(key < cur->key)
		{
			parent->left = cur->left;
		}
		else
		{
			parent->right = cur->left;
		}
	}

	free(cur);
}

static void RemoveHasLeftANDRight(BSTreeNode* cur)
{
	BSTreeNode*  del = cur->left;
	BSTreeNode*  delParent = NULL;

	while(del->right!=NULL)
	{
		delParent = del;
		del = del->right;
	}

	cur->key = del->key;
	if(dalParent ==NULL)
	{
		cur->left = del->left;
	}
	else 
	{
		delParent->right = del->left;
	}

	free(cur);
}



void Test()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert(&root, 5); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 3); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 7); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 1); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 4); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 6); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 8); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 0); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 2); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 9); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 10); printf("插入%s\n", r ? "成功" : "失败");

	
	r = BSTreeFind(root, 9); printf("查找 9 %s\n", r ? "成功" : "失败");
	r = BSTreeFind(root, 10); printf("查找 10 %s\n", r ? "成功" : "失败");
}
