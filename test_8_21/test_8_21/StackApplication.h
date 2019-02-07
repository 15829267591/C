#pragma once
#include "Stack.h"
#include <string.h>
#include <stdio.h>


int isBrscket(char ch)
{
    if(('('== ch||')'== ch)||
		('['== ch||']'== ch)||
		('{'== ch||'}'== ch))
	{
		return 1;
	}
	return 0;
}
int MatchBrsckets( char* pStr)
{
	int i =  0;
	int len = 0;
	Stack s;
	
	if(NULL==pStr)
	{
		return 1;
	}
	StackInit(&s);
	len = strlen(pStr);
	for(i=0; i<len; i++)

	{
	
         if(isBrscket(pStr[i]))
		 {
			 if('('==pStr[i] ||'['==pStr[i]||'{'==pStr[i])
			 {
				 StackPush(&s,pStr[i]);
			 }
			 else
			 {
				 if(StackEmpty(&s))
				 {
					 printf("�����ű������Ŷ࣡����\n");
					 return 0;
				 }
				 else
				 {
					 char top = StackTop(&s);
					 if( '('==top &&')'==pStr[i]||
						 '['==top &&']'==pStr[i]||
						 '{'==top &&'}'==pStr[i])
					 {
						 StackPop(&s);
					 }
					 else
					 {
						 printf("�����ű������Ŷ�\n");
							 return 0;
					 }
				 }
			 }
		 }
	}
	if(!(StackEmpty(&s)))
	{
		printf("�����ű������Ŷ�\n");
			return 0;
		
	}
	else
	{
		printf("ƥ����ȷ\n");
		return 1;
	}
}



void TestMatchBrsckets()
{
	
	char a[] = "(())abc{[(])}";
	char b[]="(()))abc{[]}";
	char c[] ="(()()abc{[]}";
	char d[] = "(())abc{[]()}";
	   
	MatchBrsckets(a);
	MatchBrsckets(b);
	MatchBrsckets(c);
	MatchBrsckets(d);
	

}


void BracketMatch(const char *sequence, int size)
{
	int i = 0;
	char ch =0;
	char leftBracket=0;
	Stack stack;
	StackInit(&stack);
	
	


for(i=0; i<size; i++)
{
	ch = sequence[i];
	switch(ch)
	{
	case'(':
	case'[':
	case'{':
		StackPush(&stack,(StackDataType)ch);
		break;
	case')':
	case']':
	case'}':
		if(StackEmpty(&stack))
		{
			printf("�����Ŷ���\n");
			StackDestroy(&stack);
			return ;
		}
		 leftBracket = (char)StackTop(&stack);
		 StackPop(&stack);
		 if(leftBracket =='('&& ch!=')')
		 {
			 printf("��ƥ��\n");
			 return;

		 }
		 if(leftBracket=='['&& ch!=']')
		 {
			 printf("��ƥ��\n");
			 return ;
		 }
		 if(leftBracket=='{' &&ch!='}')
		 {
			 printf("��ƥ��\n");
			 return;
		 }
	default:
		break;
	}

	}
if(!StackEmpty(&stack))
{
	printf("�����Ŷ���\n");
	return;
}
  printf("����ƥ��\n");
}

void TestBracket()
{
	int i = 0;
	const char* seqs[]=
	{
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};
	for(i=0; i<4; i++)
	{
		BracketMatch(seqs[i],strlen(seqs[i]));
	}
}


�沨��
auto
���Թ�
1.�������Ƿ�Ϸ�IsValidEntry();
2.�����һ���Ƿ���ͨ·��