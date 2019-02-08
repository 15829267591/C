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

//堆的初始化
void HeapInit(Heap* pH,int src[], int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		pH->array[i] = src[i];
	}
		pH->size = size;
}

//向下调整(前提是满足堆的性质)


	void HeapAdjustDown(Heap* pH,int root)
	{
	int left = 0;
	int right = 0;
	int maxChild = 0;
	int t = 0;
	int parent = root;

	while(1)
	{
	//先判断有没有孩子（即就是有没有叶子结点）
	//如何判断，利用数组，看孩子的下标是否越界
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

	//1.判断是否是叶子结点（为什么判断）因为到叶子结点就不用调整了
	//利用数组下标是否越界

	//2.找两个孩子中大的一个
	//3.如果根比最大的孩子大，调整结束
	//4.否则，交换根

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



//向上调整
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



//构造堆
void HeapMake(Heap* pH)
{
	//找最后一个非叶子结点(叶子结点的父母结点)

	int i = 0;
	for(i=(pH->size-2)/2; i>=0; i--)
	{
		 HeapAdjustUp(pH, i);
	}
}
//删除堆顶元素
void HeapPop(Heap * pH)
{
	pH->array[0] = pH->array[pH->size-1];
	pH->size--;
	HeapAdjustDown(pH, 0);
}
//获取堆顶元素
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


	printf("建堆完成\n");
}




void ArrayAdjustDown(int array[], int size, int root)
{
	int parent = root;
	int maxChild = 0;
	int t= 0;

	while (1) {
		// 先判断有没有孩子（叶子结点）
		// 数组角度去想	-> 孩子的下标是否越界
		// 只要判断左孩子的下标（因为是完全二叉树)
		int left = parent * 2 + 1;
		if (left >= size) {
			// 越界，没有左孩子，也肯定没有右孩子
			return;
		}

		// 一定有左孩子
	    maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2] > array[left]) {
			// 前一个条件是判断右孩子有没有
			// 后一个条件判读是右孩子是否比左孩子大
			maxChild = 2 * parent + 2;
		}

		if (array[parent] > array[maxChild]) {
			return;
		}

		// 交换 root 和 maxChild 下标所在的值
		 t = array[parent];
		array[parent] = array[maxChild];
		array[maxChild] = t;

		parent = maxChild;
	}
}




void HeapSort(int array[],int size)
{
	//第一步 建大堆
	int i= 0;
	int j = 0;
	int s = 0;
	for(i=(size-2)/2; i>=0; i--)
	{
		ArrayAdjustDown(array, size, i);
	}
	//排序
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


	printf("成功\n");
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

	//建堆
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

	printf("成功\n");
}