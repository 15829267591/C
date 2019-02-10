#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void SeqListInit(SeqList* pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

void SeqListDestroy(SeqList* pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

void SeqListPushFront(SeqList* pSeq, DataType data)
{
	int i;
	assert(pSeq != NULL);
	if(pSeq ->size >=MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return ;
	}

	for(i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i-1];
	}
		pSeq->array[0] = data;
		pSeq->size++;

}

void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	if(pSeq ->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return ;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

void SeqListInsert(SeqList* pSeq, int pos, DataType data)
{
	int i;
	assert(pSeq != NULL);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}
    for(i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i-1];

	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

void SeqListPopFront(SeqList* pSeq)
{
	int i;
	assert(pSeq != NULL);
	if(pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	for(i = 0; i < pSeq->size; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];

	}
	pSeq->size--;
}

void SeqListPopBack(SeqList* pSeq)
{
	assert(pSeq != 0);
	if(pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}
void SeqListEarse(SeqList* pSeq, int pos)
{
	int i;
	assert(pSeq != NULL);
	if(pSeq ->size <= 0)
	{
      printf("空了\n");
	  assert(0);
	  return;
	}
	for(i = pos; i < pSeq->size; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
}

void  Print(SeqList* pSeq)
{
	int i;
	assert(pSeq != NULL);
	for(i = 0; i < pSeq->size; i++)
	{
		printf("%d ",pSeq->array[i]);
	}
	printf("\n");
}

int SeqListFind(SeqList* pSeq, DataType data)
{
	int i;
	for(i = 0; i < pSeq->size; i++)
	{
		if(pSeq ->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* pSeq, DataType data)
{
	int i;
	int j;
	DataType * newArray = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	for(i = 0,j = 0; i < pSeq->size; i++)
	{
		if(data != pSeq->array[i])
		{
			newArray[j] = pSeq->array[i];
			j++;
		}
	}
	for(i = 0; i < j; i++)
	{
		pSeq->array[i] = newArray[i];

	}
	pSeq->size = j;
	free(newArray);
}

int SeqListSize(SeqList* pSeq)
{
	assert(pSeq != NULL);
	return pSeq->size;
}

int SeqListEmpty(SeqList* pSeq)
{
	return pSeq->size == 0;
}

int SeqListFull(SeqList* pSeq)
{
	return pSeq->size == MAX_SIZE;
}


int main()
{
    SeqList seqList;
	SeqListInit(&seqList);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 6);
	Print(&seqList);
	//SeqListPopFront(&seqList);
	//Print(&seqList);
	//SeqListInsert(&seqList, 2, 6);
	//Print(&seqList);
	//SeqListEarse(&seqList, 2);
	//Print(&seqList);
	//SeqListPopBack(&seqList);
	//Print(&seqList);
    SeqListRemoveAll(&seqList, 6);
	Print(&seqList);


	return 0;
}