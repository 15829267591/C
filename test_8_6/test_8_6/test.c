#include <stdio.h>
#include <assert.h>
int my_strlen(const char* src)
{
	int count = 0;
	assert(src!= NULL);
	while(*src++)
	{
       
	   count++;
	}
	return count;

}
int main()
{
	char arr[] = "abedferh";
	int ret = my_strlen(arr);
    printf("%d\n", ret);
	return 0;
}



//#include <stdio.h>
//#include<assert.h>
//void my_strcpy(char *dest, const char* src)
//{
//	assert(dest!=NULL);
//	assert(src!=NULL);
//	while(*dest++ = *src++)
//	{
//       ;
//	}
//	
//
//}
//int main ()
//{
//	char arr1[10] = {0};
//	char arr2[] = "hello";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}