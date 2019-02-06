#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

union Un
{   
	char c;
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un)); 
	return 0;
}
