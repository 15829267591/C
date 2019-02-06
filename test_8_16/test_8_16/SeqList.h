#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList
{   
	DataType array[MAX_SIZE];
	int size;
	
} SeqList;
//��ʼ��
void SeqListInit(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}
//����
void SeqListDestroy(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}
//��
//β��
void SeqListPushBack(SeqList* pSeq,DataType data)
{
	assert(pSeq !=NULL);
	//�������
	if(pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);
		return;
	}

	//�������
    pSeq->array[pSeq->size] = data;
	pSeq->size++;
   
}

//ͷ��
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	int i = 0;
    assert(pSeq != NULL);
	//����
	if(pSeq->size <=0)
	{
       printf("����\n");
        return ;
	}
	//�������
	
	for(i=pSeq->size; i>0; i--)
	{
        pSeq->array[i] = pSeq->array[i-1];
	}
	pSeq->array[0] = data;
	pSeq->size++;
}

//����
void SeqListInsert(SeqList* pSeq,int pos, DataType data)
{	
	int i = 0;
	assert(pSeq != NULL);
	assert(pos>=0 && pos<=pSeq->size);
	//����
	if(pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);
		return;
	}
    

	for(i=pSeq->array[pSeq->size]; i>pos; i--)
	{
		pSeq->array[i] = pSeq->array[i-1];
	}
	pSeq->array[pos] = data;
	pSeq->size++;

}







//βɾ
void SeqListPopBack(SeqList* pSeq)
{

    assert(pSeq != NULL);
	//�������
	if(pSeq->size <=0)
	{
		printf("����");
			return ;
	}

	//�������
	pSeq->size--;
}
//ͷɾ

void SeqListPopFront(SeqList* pSeq)
{
	int i = 0;
    assert(pSeq!=NULL);
	if(pSeq->size<=0)
	{
		printf("����");
		assert(0);
		return;
	}
    for(i=0; i<pSeq->size-1; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
		pSeq->size++;
	}
}
void SeqListErase(SeqList* pSeq,int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos>=0 && pos<=pSeq->size);
	if(pSeq->size <=0)
	{
		printf("����");
		assert(0);
		return ;
	}
	for(i=pos; i<pSeq->size-1; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
		pSeq->size--;
	}
}
	void SeqListPrint(const SeqList* pSeq)
	{
		int i = 0;
		assert(pSeq !=NULL);
        for(i=0; i<pSeq->size; i++)
		{
			printf("%d ",  pSeq->array[i]);
		}
		printf("\n");

	}
	void Test()
	{
		SeqList seqList;
		SeqListInit(&seqList);
		SeqListPushBack(&seqList,1);
		SeqListPushBack(&seqList,2);
		SeqListPushBack(&seqList,3);
		SeqListPushBack(&seqList,4);
		SeqListPushBack(&seqList,5);
		SeqListPrint(&seqList);
	 //   SeqListPopBack(&seqList);
		//SeqListPrint(&seqList);
		//SeqListPushFront(&seqList,0);
		//SeqListPrint(&seqList);
		//SeqListInsert(&seqList,2,3);//����֮���������
		//SeqListPrint(&seqList);
		//SeqListPopFront(&seqList);
		//SeqListPrint(&seqList);//ȫɾ��
		SeqListErase(&seqList,1);
		SeqListPrint(&seqList);
	}

