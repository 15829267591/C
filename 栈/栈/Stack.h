#pragma once

#include <assert.h>
typedef int StackDataType;

#define  MAX_SIZE (100)
typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int top;
}Stack;


// ��ʼ��/����
// ����ֻ�ܴ�ջ����/ɾ��ֻ��ɾ��ջ����/�飨ֻ�ܲ鿴ջ��Ԫ�أ�
// ���� / �Ƿ�� / �Ƿ���
// �� -> ˳����β��
// ɾ -> ˳����βɾ
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
	//���˶��Ծʹ��ˣ�
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