#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//接口（初始化、销毁、增删查改）

void SeqListInit(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

void SeqListDestroy(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了!");
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i-1];
	}
	pSeq->array[0] = data;
	pSeq->size++;
}

void SeqListInsert(SeqList* pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}
	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	
	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

void SeqListPopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}

void SeqListPopFront(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size < 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

void SeqListErase(SeqList* pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size-1);
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

void SeqListPrint(SeqList* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d",pSeq->array[i]);
	}
	printf("\n");
}

//查找第一个遇到的数的下标
int SeqListFind(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data == pSeq->array[i])
		{
			return i;
		}
	}
	return -1;
}

//删除的第二种形态（根据数据）
//删除遇到的第一个数
void SeqListRemove(SeqList* pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1)
	{
		return;
	}
	SeqListErase(pSeq, pos);
}

//删除遇到的每个数
void SeqListRemove2(SeqList* pSeq, DataType data)
{
	int i,j;
	assert(pSeq);
	for ( i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;
}

void Test()
{
	// 1.
	SeqList seqList;
	SeqListInit(&seqList);	// 1. seqList， 2. &seqList	// 1）. 指针空间更小 2）.改变值 

	// 2.
	//SeqList *pSeqList;
	//pSeqList = SeqListInit();

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);

	SeqListPrint(&seqList);

	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);


	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPushFront(&seqList, 30);
	SeqListPushFront(&seqList, 40);

	SeqListPrint(&seqList);

	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);

	SeqListInsert(&seqList, 4, 100);
	SeqListPrint(&seqList);
	SeqListErase(&seqList, 4);
	SeqListPrint(&seqList);
}
int main()
{

	Test();
	getchar();
	return 0;
}