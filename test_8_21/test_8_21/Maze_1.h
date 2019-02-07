#pragma once
#include <stdio.h>
#include <assert.h>
#include "Stack.h"

//typedef struct Position
//{
//	int _x;
//	int _y;
//}Position;

#define ROWS 6
#define COLS 6

typedef struct
{
	int x;
	int y;
}Position;

typedef Position StackDataYtpe;
#define MAX_SIZE (100)

//栈代码
typedef struct Stack
{
	StackDataType  array[MAX_SIZE];
	int  top;//类似size的作用
}Stack;

void StackInit(Stack * pStack)
{
	assert(pStack);
	pStack->top = 0;
}
  
void StackDestroy(Stack* pStack)
{
	assert(pStack);
	pStack->top = 0;
}

int StackEmpty(const Stack* pStack)
{
	assert(pStack);
	return pStack->top==0;
}
void StackPush(Stack * pStack, StackDataType data)
{
	assert(pStack);
	if(pStack->top == MAX_SIZE)
	{
		printf("栈已满");
		return ;
	}

	pStack->array[pStack->top++] = data;

}
void StackPop(Stack* pStack)
{
	assert(pStack);
	if(StackEmpty(pStack))
	{
		printf("栈已空");
		return;
	}
	pStack->top--;

}

StackDataType StackTop(const Stack* pStack)
{
	assert(pStack);

	return pStack->array[pStack->top-1];
}

int StackSize(const Stack* pStack)
{
	assert(pStack);
	return pStack->top;
}

int StackFull(const Stack* pStack)
{
   assert(pStack);

	return pStack->top>=MAX_SIZE;

}
//栈代码
typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;

intgMaze[ROWS][COLS] = {{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 }};

Position gEntry = {5,2};
int IsExit(Position pos)
{
	if(pos.x == COLS-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int CanPass(Position pos)
{
	if(pos.x>= ROWS-1)
	{
		return 0;
	}
	if(pos.y>=COLS-1)
	{
		return 0;
	}
	return gMaze[pos.x][pos.y] ==1;
}


void PrintPath(Stack *pStack)
{
	int i = 0;
	Position at;
	for(; i<pStack->top; i++)
	{
		at = pStack->array[i];
		printf("x = %d, y = %d\n", at.x,at.y);
	}
}

Stack path;
Stack min;

void PrintMaza()
{
	int i = 0;
	for(i=0; i<ROWS; i++)
	{
		int j = 0;
		for(j=0; j<COLS; j++)
		{
			if(gMaze[i][j] == 0)
			{
              printf("▋");
			}
			else if(gMaze[i][j]==1)
			{
				printf(" ");
			}
			else if(gMaze[i][j]==2)
			{
				printf("¤");
			}
		}
	  printf("\n");
	}
	printf("\n\n");
}

void RunMazeRec(Position at)
{
	Position next;
	StackPush(&path, at);

	gMaze[at.x][at.y] = 2;
	PrintMaze();
}






















//
////判断是否是出口
//int IsExit(Maze* m, Position cur, Position entry)
//{
//	if(cur._x==entry._x&& cur._y==entry._y)
//		return 0;
//	if(0==cur._x || MAX_ROW-1 == cur._x ||
//		0== cur._y || MAX_COL-1 == cur._y)
//	{
//		return 1;
//	}
//	return 0;
//
//
//	//if(1==m->_map[cur._x][cur._y])
//	//	return 1;
//
////错误有问题？上面
//	return 0;
//}
//
////初始化迷宫
//void InitMaze(Maze* m,int map[][MAX_COL])//INT*
//{
//	int i = 0;
//    if(NULL == m)
//		return ;
//	for(i=0; i<MAX_ROW; ++i)
//	{
//	int j = 0;
//	for(j=0; j<MAX_COL; ++j)
//	{
//		m->_map[i][j] = map[i][j];
//	}
//
//	}
//}
//
////入口是否合法
//int IsValidEntry(Maze*m, Position entry)
//{
//	assert(m);
//	if(0==entry._x||entry._x==MAX_ROW-1 ||entry._y==0||entry._y==MAX_COL-1)
//	
//		return 1==(m->_map[entry._x][entry._y]);
//	
//}
//
//
////
//void PassMaze(Maze*m , Position entry, Stack *s)
//{
//    Position cur, next;
//	assert(m);
//	if(!IsValidEntry(m, entry))
//	{
//		printf("非法的迷宫入口！");
//			return;
//	}
//
//	StackInit(s);
//	StackPush(s, entry);
//	
//	//上 左 右，下
//	//什么情况占为空
//	//退回起点
//
//    while(!StackEmpty(s))
//	{
//		cur = StackPop(s);
//		m->_map[cur._x][cur._y] = 2;
//
//		if(IsExit(s, cur, entry))
//		{
//			return ;
//		}
//		next = cur;
//	    next._x-=1;
//	   if(IsPass(&m, next ))
//	 {
//        StackPush(s, next);
//		continue;
//	 }
//	   //zuo
//		next = cur;
//	    next._y-=1;
//	   if(IsPass(&m, next ))
//	 {
//        StackPush(s, next);
//		continue;
//	 }
//	   //you
//	   		next = cur;
//	    next._y+=1;
//	   if(IsPass(&m, next ))
//	 {
//        StackPush(s, next);
//		continue;
//	 }
//	   //xia
//	   		next = cur;
//	    next._x+=1;
//	   if(IsPass(&m, next ))
//	 {
//        StackPush(s, next);
//		continue;
//	 }
//
//	}
//}
//
//
//
//
//
//
//
//
////打印迷宫
//void PrintMaze(Maze* m,int map[][MAX_COL])
//{
//	int i = 0;
//    if(NULL == m)
//		return ;
//	for(i=0; i<MAX_ROW; ++i)
//	{
//	int j = 0;
//	for(j=0; j<MAX_COL; ++j)
//	{
//		printf("%d ", m->_map[i][j]);
//	}
//   printf("\n");
//	}
//}
//
////是否能走
//int IsPass(Maze* m, Position cur)
//{
//	if(i == m->_map[cur._x][cur._y])
//		return 1;
//
//	return 0;
//}
//
//
//void TestMaze_1()
//{
//	int map[MAX_ROW][MAX_COL] = {{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 0 },
//	{ 0, 0, 1, 0, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 }};
//
//	Maze m;
//	Stack s;
//	InitMaze(&m, map);
//	PrintMaze(&m, map);
//
//	StackInit(&s);
//	entry._x = 5;
//	entry._y = 2;
//	PassMaze(&m, entry, &s);
//	PrintMaze(&m, map);
//
//}