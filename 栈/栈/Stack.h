#pragma once

#include <assert.h>
typedef int StackDataType;

#define  MAX_SIZE (100)
typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int top;
}Stack;


// 初始化/销毁
// 增（只能从栈顶）/删（只能删除栈顶）/查（只能查看栈顶元素）
// 个数 / 是否空 / 是否满
// 增 -> 顺序表的尾插
// 删 -> 顺序表的尾删
void StackInit(Stack* pStack)
{
	pStack->top = 0;
}
void StackDestroy(Stack* pStack)
{
	pStack->top = 0;
}
void StackPush(Stack* pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
	
}
void StackPop(Stack* pStack)
{
	assert(pStack->top > 0);
	pStack->top--;
}
int StackFull(Stack* pStack)
{
	return pStack->top >= MAX_SIZE;
}

int StackEmpty(Stack* pStack)
{
	//加了断言就错了；
	return pStack->top <= 0;
}
StackDataType StackTop(Stack* pStack)
{
	return pStack->array[pStack->top-1];
}
int StackSize(Stack* pStack)
{
	return pStack->top;
}