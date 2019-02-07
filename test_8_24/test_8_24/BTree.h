#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Stack.h"

typedef int TDataType;

typedef struct BTreeNode {
	TDataType	data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;


BTreeNode * CreateNode(int data)
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}




BTreeNode* CreateTree(int preOrder[], int size, int* useSize)
{
	int rootValue = preOrder[0];
	int leftUse;
	int rightUse; 
	BTreeNode* root = CreateNode(rootValue);
	 if(size<=0)
	 {
		 *useSize = 0;
		 return NULL;

	 }

	 if(rootValue==-1)
	 {
		 *useSize = 1;
		 return NULL;
	 }

	 root->left = CreateTree(preOrder+1, size-1, &leftUse);
	 root->right = CreateTree(preOrder+1+leftUse, size-1-leftUse, &rightUse);
	 *useSize = 1+leftUse+rightUse;
	 return root;
}



//遍历/前序/中序/后序
void PreOrder(BTreeNode* root)
{
	if(root ==NULL)
	{
		return ;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);

}

void InOrder(BTreeNode* root)
{
	if(root == NULL)
	{
		return ;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTreeNode* root)
{
	if(root ==NULL)
	{
		return ;

	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//求结点个数
//1.用后序遍历解决
int count = 0;
void GetSize1(BTreeNode* root)
{
    if(root==NULL)
	{
		return ;
	}
	GetSize1(root->left);
	GetSize1(root->right);
	count++;
}
//子问题
int GetSize2(BTreeNode* root)
{
	int left = 0;
	int right = 0;
	if(root==NULL)
	{
		return 0;
	}
	 left = GetSize2(root->left);
	 right = GetSize2(root->right);
	return left+right+1;
}

int LeafSize(BTreeNode* root)
{
	int left = 0;
	int right = 0;
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL&&root->right==NULL)
	{
		return 1;
	}
	left = LeafSize(root->left);
	right = LeafSize(root->right);

    return left+right;

}

int LeafSizeK(BTreeNode* root,int k)
{
	int left = 0;
	int right = 0;
	assert(k>=1);
	//空树
	if(root==NULL)
	{
		return 0;
	}
	if(k==1)
	{
		return 1;
	}

	left = LeafSizeK(root->left, k-1);
	right = LeafSizeK(root->right, k-1);
	return left+right;

}

//求深度
#define MAX(a,b) ((a)>(b)?(a):(b))
int GetHight(BTreeNode* root)
{
	int left = 0;
	int right = 0;
	if(root==NULL)
	{
		return 0;
	}

	left = GetHight(root->left);
	right = GetHight(root->right);
	return (MAX(left,right)+1);
	
}

//找数据，前提是data不能重复
BTreeNode* Find(BTreeNode* root, TDataType data)
{
	BTreeNode* result = NULL;
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==data)
	{
		return root;
	}
	result = Find(root->left, data);
	if(result!=NULL)
	{
       return result;
	}
	
	result = Find(root->right, data);
	if(result!=NULL)
	{
		return result;
	}
	
	else
	{
		return NULL;
	}

}




//非递归
//前序(右子树没有被遍历过)
void PreOrderLoop(BTreeNode* root)
{
	Stack stack;
	
	BTreeNode* cur;
	BTreeNode* top;
    StackInit(&stack);
	cur = root;
	while (cur!=NULL||!StackEmpty(&stack))
	{
		while(cur!=NULL)
		{
			printf("%d ", cur->data);
			
			StackPush(&stack, cur);
            cur = cur->left;
		}

		top = StackTop(&stack);
		StackPop(&stack);

		cur = top->right;
	}
	
}

//中序(右子树和根没有被遍历过)
void InOrderLoop(BTreeNode* root)
{
  Stack stack; 
  BTreeNode* cur;
  BTreeNode* top;
  StackInit(&stack);
  cur = root;
  while(cur != NULL||!StackEmpty(&stack))
  {
     while(cur!= NULL)
	 {
		 StackPush(&stack, cur);
		 cur = cur->left;
	 }
	 //此时左子树已经遍历完了
     
	 top = StackTop(&stack);
	 StackPop(&stack);
	 printf("%d ", top->data);

	 cur = top->right;


  }
}



void PostOrderLoop(BTreeNode * root)
{
	Stack stack;
	BTreeNode* cur;
	BTreeNode* top;
	BTreeNode* last = NULL;
	
	StackInit(&stack);
    cur = root;
	while(cur!= NULL|| !StackEmpty(&stack))
	{
		while(cur!=NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//左子树已经遍历完

		top = StackTop(&stack);

		if(top->right==NULL||top->right==last)
		{
			printf("%d ", top->data);
			StackPop(&stack);
		    last = top;
		}
		else
		{

			cur = top->right;
		}
	}
}

//求镜像
void Mirror1(BTreeNode* root)
{
	BTreeNode* t = NULL;
     if(root==NULL)
	 {
       return ;

	 }
	 Mirror1(root->left);
	 Mirror1(root->right);

	t = root->left;
	 root->left = root->right;
	 root->right = t;
}


void Test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10  };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BTreeNode* r = NULL;

	BTreeNode *root = CreateTree(preOrder, size, &usedSize);
	GetSize1(root);printf("%d\n", count);
	printf("结点个数:%d\n", GetSize2(root));
	printf("叶子结个数:%d\n", LeafSize(root));
	printf("第三层的结点个数:%d\n", LeafSizeK(root,3));
	printf("深度:%d\n", GetHight(root));
	r = Find(root, 3);

	PreOrderLoop(root); printf("\n");
	InOrderLoop(root);printf("\n");
	PostOrderLoop(root); printf("\n");

	printf("成功\n");
}
