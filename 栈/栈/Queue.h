#pragma once

typedef  int QDataType;

typedef  struct QNode
{
	QDataType data;
	struct QNode* next;
	
}QNode;

typedef struct Queue
{
  struct QNode* front;
  struct QNode* rear;

}Queue;

void QueueInit(Queue* pQueue)
{
	pQueue->front = pQueue->rear = NULL'
}

void QueueDestroy(Queue* pQueue)
{
	QNode* cur;
	QNode* next;
	for(cur=pQueue->front; cur!=NULL; cur=next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

void QueuePush(Queue* pQueue, QDataType data)
{
	QNode* node = (QNode*)malloc(sizoef(QNode));
	node->data = data;
	node->next = NULL;
	if(pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = node;
	}
	else
	{
	   pQueue->rear->next = node;
	   rear = node;
	}
}

void QueuePop(Queue* pQueue)
{
    assert(pQueue != NULL)
	assert(pQueue->front != NULL)
	if(pQueue->front == pQueue->rear)
	{
		free(pQueue->front);
		pQueue->front = pQueue->rear = NULL;
	}
	else
	{
		QNode* del = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(del);
	}
}

QDataType QueueTop(Queue* pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);
	return pQueue->front->data;
}

int QueueEmpty(Queue* pQueue)
{
	return pQueue->front == NULL;
}

int QueueSize(Queue* pQueue)
{
	QNode* cur;
	int size = 0;
	for(cur = pQueue->front; cur!=NULL; cur = cur->next)
	{
		size++;
	}
	return size;
}
























//
//typedef int QDataType
//
//typedef struct QNode
//{
//   QDataType data;
//   struct QNode* next;
//}QNode;
//
//typedef  struct Queue
//{
//  QNode* rear;
//  QNode* front;
//}Queue;
//
//
//// ��ʼ��/����
//
//// ���루��β���룩/ɾ������ͷɾ����/�鿴��������
//void QueueInit(Queue* pQueue)
//{
//	pQueue->front = pQueue->rear = NULL;
//
//}
//
//void QueueDestroy(Queue* pQueue)
//{
//	QNode* cur;
//	QNode* next;
//	for(cur = pQueue->front; cur->next != NULL; cur = next)
//	{
//		next = cur->next;
//		free(cur);
//	}
//	pQueue->front = pQueue->rear = NULL;
//}
//static QNode* CreateNode(QDataType data)
//{
//	QNode* node = (QNode*)malloc(sizeof(QNode));
//	node->data = data;
//	node->next = NULL;
//
//	return node;
//}
//
////��壨��β���룩
//void QueuePush(Queue* pQueue, QDataType data)
//{
//  QNode* newNode = CreateNode(data);
//  if(pQueue->front = NULL)
//  {
//	  pQueue->front = pQueue->rear = newNode;
//	  return;
//  }
//    pQueue->rear->next = newNode;
//	pQueue->rear = newNode->next;
//
//}
//
////ͷɾ
//
//void QueuePop(Queue* pQueue)
//{
//	  assert(pQueue);
//	  assert(pQueue->front!=NULL);
//	  QNode* del;
//	  pQueue->front = pQueue->front->next;
//	  free(del);
//	  if(pQueue->front == NULL)
//	  {
//		  pQueue->rear = NULL;
//	  }
//
//}
//
////��ȡ����Ԫ��
//QDataType  QueueFront(Queue* pQueue)
//{
//	assert(pQueue);
//	assert(pQueue->front!=NULL);
//	return pQueue->front->data;
//}
////�Ƿ�Ϊ��
//
//int QueueEmpty(const Queue* pQueue)
//{
//	return  pQueue->front == NULL;
//}
//
////Ԫ�ظ���
//
//int QueueSize(Queue* pQueue)
//{
//	QNode* cur;
//	int size = 0;
//	for(cur = pQueue->front; cur->next != NULL; cur = cur->next)
//	{
//		size++;
//	}
//	return size;
//}