#pragma once
#include <assert.h>
#include <stdio.h>


typedef int StackDataType;
//typedef char StackDataType;
//typedef Position StackDataType;

#define MAX_SIZE (100)

typedef struct Stack
{
	StackDataType  array[MAX_SIZE];
	int  top;//����size������
}Stack;

void StackInit(Stack * pStack)
{
	assert(pStack);
	pStack->top = 0;
}
  
void StackDestroy(Stack* pStack)
{
	assert(pStack);
	pStack->top = 0;
}

int StackEmpty(const Stack* pStack)
{
	assert(pStack);
	return pStack->top==0;
}
void StackPush(Stack * pStack, StackDataType data)
{
	assert(pStack);
	if(pStack->top == MAX_SIZE)
	{
		printf("ջ����");
		return ;
	}

	pStack->array[pStack->top++] = data;

}
void StackPop(Stack* pStack)
{
	assert(pStack);
	if(StackEmpty(pStack))
	{
		printf("ջ�ѿ�");
		return;
	}
	pStack->top--;

}

StackDataType StackTop(const Stack* pStack)
{
	assert(pStack);

	return pStack->array[pStack->top-1];
}

int StackSize(const Stack* pStack)
{
	assert(pStack);
	return pStack->top;
}

int StackFull(const Stack* pStack)
{
   assert(pStack);

	return pStack->top>=MAX_SIZE;

}

