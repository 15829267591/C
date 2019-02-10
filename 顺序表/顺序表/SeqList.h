#pragma once

typedef int DataType;
#define MAX_SIZE (100)

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;
}SeqList;

void SeqListInit(SeqList* pSeq);
void SeqListDestroy(SeqList* pSeq);
void SeqListPushFront(SeqList* pSeq, DataType data);
void SeqListPushBack(SeqList* pSeq, DataType data);
void SeqListInsert(SeqList* pSeq,int pos, DataType data);
void SeqListPopFront(SeqList* pSeq);
void SeqListPopBack(SeqList* pSeq);
void SeqlistPopErase(SeqList* pSeq, int pos);
int SeqListFind(SeqList* pSeq, DataType data);
void SeqListRemoveAll(SeqList* pSeq, DataType data);
