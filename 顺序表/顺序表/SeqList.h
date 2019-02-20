#pragma once

typedef int DataType;
#define MAX_SIZE 100
typedef struct SeqList
{
	int size;
	DataType array[MAX_SIZE];
}SeqList;

void SeqListInit(SeqList* pSeq);
void SeqListDestroy(SeqList* pSeq);
void SeqListPushBack(SeqList* pSeq, DataType data);
void SeqListPushFront(SeqList* pSeq, DataType data);
void SeqListInsert(SeqList* pSeq,int pos, DataType data);
void SeqListPopBack(SeqList* pSeq);
void SeqListPopFront(SeqList* pSeq);
void SeqListErase(SeqList* pSeq,int pos);
void SeqListPrint(SeqList* pSeq);