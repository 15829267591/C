#pragma once

#include <string.h>
#include "Stack.h"
#include <stdio.h>

void BracketMatch(const char* sequence,int size)
{
    Stack stack;
    
    int ch;
	int leftbracket;
	int i = 0;
	StackInit(&stack);
	for(i=0; i<size; i++)
	{
		ch = sequence[i];
		switch(ch)
		{
		case '{':
		case '[':
		case '(':
			StackPush(&stack, ch);
			break;
		case '}':
		case ']':
		case ')':
               if(StackEmpty(&stack))
			   {
				   printf("�����Ŷ���\n");
				   StackDestroy(&stack);
				   return;
			   }
			   leftbracket = StackTop(&stack);
			   StackPop(&stack);
			   if(leftbracket == '{'&& ch != '}')
			   {
				   printf("��ƥ��\n");
                   return;
			   }
			   if(leftbracket == '[' && ch != ']')
			   {
				   printf("��ƥ��\n");
				   return;
			   }
			   if(leftbracket == '(' && ch != ')')
			   {
				   printf("��ƥ��\n");
				   return ;
			   }
		default:
			break;
			   

		}
	}
	if(!StackEmpty(&stack))
	{
		printf("�����Ŷ���");
		return;
	}
	printf("ƥ��ɹ�\n");

}

void TestBracket()
{
	int i = 0;
	const char * seqs[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};

	for (i = 0; i < 4; i++) {
		BracketMatch(seqs[i], strlen(seqs[i]));
	}
}


//typedef enum
//{
//	OPERAND,
//	OPERATOR
//}Type;
//
//typedef enum
//{
//    ADD, SUB, MUL, DIV
//}Operator;
//
//typedef struct 
//{
//	Type type;
//	int operand;
//	Operator operator;
//}Element;
//
//int Run(Operator operator, int a,int b)
//{
//  switch(operator)
//  {
//  case ADD:
//       return a+b;
//  case SUB:
//	  return a-b;
//  case MUL:
//	  return a*b;
//  case DIV:
//	  return a/b;
//  default:
//	  assert(0);
//  }
//}
//
//int ReversePolishNotion(Element expression[], int size)
//{
//	 int op1;
//	 int op2;
//	 int result;
//	 int i = 0;
//     Stack stack;
//	 StackInit(&stack);
//     
//	 for(i=0; i<size; i++)
//	 {
//		 Element e = expression[i];
//		 switch(e.type)
//		 {
//		 case  OPERAND:
//			 StackPush(&stack, e.operand);
//			 break;
//		 case OPERATOR:
//             op1 = StackTop(&stack);
//			 StackPop(&stack);
//			 op2 = StackTop(&stack);
//			 StackPop(&stack);
//			 result = Run(e.operand, op1, op2);
//				 StackPush(&stack, result);
//			 break;
//		 default:
//			 assert(0);
//
//		 }
//	 }
//assert(StackSize(&stack) == 1);
//	result = StackTop(&stack);
//
//	return result;
//}
//
////int TestRPN()
////{
////	
////	int result;
////	Element expression[] = {
////		{
////			OPERAND,
////			2,
////			ADD	// �����ʵû���ã����д
////		},
////		{
////			OPERAND,
////			3,
////			ADD	// �����ʵû���ã����д
////		},
////		{
////			OPERATOR,
////			-1,	// �����ʵû���ã����д
////			ADD	
////		}
////		//{
////		//	OPERAND,
////		//	3,
////		//	SUB	// �����ʵû���ã����д
////		//},
////		//{
////		//	OPERATOR,
////		//	-1,	// �����ʵû���ã����д
////		//	ADD
////		//}
////	};
////
////	 result = ReversePolishNotion(expression, 3);
////
////	printf("result = %d\n", result);