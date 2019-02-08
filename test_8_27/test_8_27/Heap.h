#pragma once
#include<stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef struct Heap
{
	int array[100];
	int size;

}Heap;


static void Swap(int*a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;

}

//�ѵĳ�ʼ��
void HeapInit(Heap* pH,int src[], int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		pH->array[i] = src[i];
	}
		pH->size = size;
}

//���µ���(ǰ��������ѵ�����)


	void HeapAdjustDown(Heap* pH,int root)
	{
	int left = 0;
	int right = 0;
	int maxChild = 0;
	int t = 0;
	int parent = root;

	while(1)
	{
	//���ж���û�к��ӣ���������û��Ҷ�ӽ�㣩
	//����жϣ��������飬�����ӵ��±��Ƿ�Խ��
	left = parent*2+1;
	right = parent*2+2;
	if(left>=pH->size)
	{
		return ;
	}
	 maxChild = left;
	 if(right<pH->size&&pH->array[right]>pH->array[left])
	 {
		 maxChild = right;
	 }
	 if(pH->array[parent]>pH->array[maxChild])
	 {
		 return ;
	 }

	 t= pH->array[parent];
	 pH->array[parent] = pH->array[maxChild];
	 pH->array[maxChild] = t;
	 parent = maxChild;
	}


	}

	//1.�ж��Ƿ���Ҷ�ӽ�㣨Ϊʲô�жϣ���Ϊ��Ҷ�ӽ��Ͳ��õ�����
	//���������±��Ƿ�Խ��

	//2.�����������д��һ��
	//3.����������ĺ��Ӵ󣬵�������
	//4.���򣬽�����

void HeapAdjustDown2(Heap* pH, size_t root)
{
	size_t left = 0;
	size_t right = 0;
	size_t maxChild = 0;
	size_t parent = root;
	left = root*2+1;
	right = root*2+1;
	while(left<(size_t)pH->size)
	{
      maxChild = left;
	  if(right<(size_t)pH->size && pH->array[right]>pH->array[left])
	  {
		  maxChild = right;
	  }
	  if(pH->array[parent]>pH->array[maxChild])
	  {
		  break;
	  }
	  Swap(pH->array+maxChild,pH->array+parent);
	  parent = maxChild;
	  left = parent*2+1;
	  right = parent*2+2;

	}
}



//���ϵ���
void HeapAdjustUp(Heap *pH, int child)
{
	int parent;
	while (child > 0) {
		parent = (child - 1) / 2;
		if (pH->array[parent] >= pH->array[child]) {
			return;
		}

		Swap(pH->array + parent, pH->array + child);

		child = parent;
	}
}


void HeapPush(Heap* pH,int data)
{
	assert(pH->size<100);
	pH->array[pH->size] = data;
	HeapAdjustUp(pH, pH->size-1);
}



//�����
void HeapMake(Heap* pH)
{
	//�����һ����Ҷ�ӽ��(Ҷ�ӽ��ĸ�ĸ���)

	int i = 0;
	for(i=(pH->size-2)/2; i>=0; i--)
	{
		 HeapAdjustUp(pH, i);
	}
}
//ɾ���Ѷ�Ԫ��
void HeapPop(Heap * pH)
{
	pH->array[0] = pH->array[pH->size-1];
	pH->size--;
	HeapAdjustDown(pH, 0);
}
//��ȡ�Ѷ�Ԫ��
int HeapTop(Heap* pH)
{
	return pH->array[0];
}




void Test()
{
	int array[] = {53,17,78,9,45,65,87,23,31};
	int array1[] = {45,17,65,23,9,78,53,87,31};
	//9,17,65,23,45,78,87,53,31
	Heap heap;

	int size = sizeof(array)/sizeof(array[0]);
    
	HeapInit(&heap,array, size);
	HeapMake(&heap);
	HeapPush(&heap, 100);

	HeapPop(&heap);
	printf("%d ",HeapTop(&heap));


	printf("�������\n");
}




void ArrayAdjustDown(int array[], int size, int root)
{
	int parent = root;
	int maxChild = 0;
	int t= 0;

	while (1) {
		// ���ж���û�к��ӣ�Ҷ�ӽ�㣩
		// ����Ƕ�ȥ��	-> ���ӵ��±��Ƿ�Խ��
		// ֻҪ�ж����ӵ��±꣨��Ϊ����ȫ������)
		int left = parent * 2 + 1;
		if (left >= size) {
			// Խ�磬û�����ӣ�Ҳ�϶�û���Һ���
			return;
		}

		// һ��������
	    maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2] > array[left]) {
			// ǰһ���������ж��Һ�����û��
			// ��һ�������ж����Һ����Ƿ�����Ӵ�
			maxChild = 2 * parent + 2;
		}

		if (array[parent] > array[maxChild]) {
			return;
		}

		// ���� root �� maxChild �±����ڵ�ֵ
		 t = array[parent];
		array[parent] = array[maxChild];
		array[maxChild] = t;

		parent = maxChild;
	}
}




void HeapSort(int array[],int size)
{
	//��һ�� �����
	int i= 0;
	int j = 0;
	int s = 0;
	for(i=(size-2)/2; i>=0; i--)
	{
		ArrayAdjustDown(array, size, i);
	}
	//����
	for(j=0; j<size; j++)
	{
		s = size-1-j;
		Swap(array, array+s);
		ArrayAdjustDown(array, size-1-j, 0);
	}

}

void TestSort()
{
	int array[] = { 1, 4, 9, 4, 2, 7, 8, 5, 3, 6, 2, 2, 3 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);


	printf("�ɹ�\n");
}

int * TopK(int array[], int size, int k)
{
	int m = 0;
	int i = 0;
    int * heapArray = (int *)malloc(k*sizeof(int));
		assert(heapArray);
	for(i=0; i<k; i++)
	{
	heapArray[i] = array[i];

	}

	//����
	for(i=(size-2)/2; i>=0; i--)
	{
		ArrayAdjustDown(heapArray, k, i);

	}

	//
	for(m=k; m<size; m++)
	{
       if(array[m]>heapArray[0])
	   {
        continue;
	   }
       heapArray[0] = array[m];
       ArrayAdjustDown(heapArray, k ,m);
	}
	return heapArray;
}

void TestTopK()
{
	int array[] = { 1, 4, 9, 4, 2, 7, 8, 5, 3, 6, 2, 2, 3 };
	int size = sizeof(array) / sizeof(int);

	int *r = TopK(array, size, 3);

	printf("�ɹ�\n");
}