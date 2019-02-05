#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	char* p = "abcedtr";
	strcpy(p, "hello");
	printf("%s\n", p);
	return 0;
}