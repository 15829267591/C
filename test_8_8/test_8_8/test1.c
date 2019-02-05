#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
void* my_memmove(void* dest, const void*src, size_t count)
{
	int* ret = dest;
	assert(dest !=NULL);
	assert(src !=NULL);
	if(src>dest)//前——后
	{
       while(count--)
	   {
		   *(char*)dest = *(char *)src;
		   dest = (char*)dest+1;
		   src = (char*)src+1;
	   }
	}
	else //后向前
		while(count--)
		{
		    *((char*)dest+count)=*((char*)src+count);
		}
		return ret;
}
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	my_memmove(arr,arr+2,16);
	return 0;
}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	void* ret= dest;
//	char* pd = (char*)dest;
//	char* ps = (char*)src;
//	assert(dest !=NULL);
//	assert(src !=NULL);
//
//	while(count--)
//	{
//		*pd++ = *ps++;
//	}
//	//while(count--)
//	//{
//	//	*(char *)dest = *(char*)src;
//	//	dest = (char*)dest+1;
//	//	src = (char*)src+1;
//
//
//	//}
//	return ret;
//}
//int main()
//{
//	int  arr1[10] = {0};
//	int  arr2[20] = {1,2,3,4,5,6,7,8,9,10};
//	my_memcpy(arr1, arr2, 20);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//char* my_strstr(const char*src, const char*subsrc)
//{
//	const char* s1 = src;
//	const char* s2 = subsrc;
//    const char* cur = src;
//	assert(src !=NULL);
//	assert(subsrc !=NULL);
//	
//	while(*cur)
//	{
//		s1 = cur;
//		s2 = subsrc;
//		while(*s1 && *s2 && (*s1==*s2))
//		{
//             s1++;
//			 s2++;
//		}
//		if(*s2=='\0')
//			return (char*)cur;
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char* src = "abbbcedf";
//	char* subsrc = "bbc";
//	char* ret = my_strstr(src,subsrc);
//	printf("%s\n",ret);
//	return 0;
//}
//
//
//








//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* src = "abbbcedf";
//	char* subsrc = "bbc";
//	char* ret = strstr(src,subsrc);
//	printf("%s\n",ret);
//	return 0;
//}
//
//
//
//



//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strcmp(const char*src, const char* dst)
//{
//	assert(src !=NULL);
//	assert(dst !=NULL);
//	while(*src ==*dst)
//	{
//		if(*src=='\0')
//			return 0;
//		src++;
//		dst++;
//	}
//	return *src-*dst;
//}
//int main()
//{
//	int ret = 0;
//	char* p1 = "abxdef";
//	char* p2 = "abxdesdf";
//    ret = my_strcmp(p1, p2);
//	printf("%d\n",ret);
//	return 0;
//}





//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	//找到目标的'\0'
//	char* ret = dest;
//	assert(dest !=NULL);
//	assert(src !=NULL);
//	while(*dest)
//	{
//		dest++;
//	}
//	while(*dest++=*src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[20] = "hello";
//	my_strcat(arr, " bit");
//	printf("%s\n",arr);
//	return 0;
//}
//#include <stdio.h>
//#include<assert.h>
//char * my_strcpy(char* des, const char*src)
//{
//	char* ret = des;
//	assert(des !=NULL);
//	assert(src !=NULL);
//	while(*des++=*src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[10]={0};
//
//	my_strcpy(arr,"hello");
//	printf("%s\n",arr);
//	return 0;
//}


//指针方法冒泡
//#include <stdio.h>
//void bubble_sort(int* arr, int sz)
//{
//	int* start = arr;
//	int* end = arr+sz-1;
//	int* cur = NULL;
//	while(start<end)//趟数
//	{
//		cur = start;
//		while(cur<end)
//		{
//		if(*cur < *(cur+1))
//		  {
//			int temp = *cur;
//			*cur = *(cur+1);
//			*(cur+1) = temp;
//		  }
//		   cur++;
//		}
//		end--;
//	}
//}
//void bubble_sort(int arr[], int sz)
//{
//	//趟数
//	int i = 0;
//	int flag = 0;
//	for(i=0; i<sz-1; i++)
//	{	
//		//每一趟比较
//		int j = 0;
//		for(j=0; j<sz-1-i; j++)
//		{
//			if(arr[j]<arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//				flag = 1;
//			}
//		}
//		if(flag == 0)
//			break;
//
//	}
//}
//void print_arr(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//		printf("%d ",arr[i]);
//}
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	print_arr(arr, sz);
//	return 0;
//}

//将内容逆序
//#include <stdio.h>
//void reverse(int* left , int* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//
//	while(left<right)
//	{
//        int temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,0}
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	reverse(&arr[0], &arr[sz-1]);
//	return 0;
//}
//
 


//#include <stdio.h>
//void reverse(int arr[],int left,int right)
//{
//	 while(left<right)
//	{
//	int temp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = temp;
//	left++;
//	right--;
//	}
//}
//void print_arr(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//		printf("%d ",arr[i]);
//}
//int main()
//{
//	
//	int arr[] ={1,2,3,4,5,6,7,8,9,0};
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//	int sz = right+1;
//    reverse(arr, left, right);
//	print_arr(arr, sz);
//		return 0;
//}








//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str !=NULL);
//	while(*str !='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	char * str = "abcdef";
//    ret = my_strlen(str);
//	printf("%d\n",ret);
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d",&n);
//	for(i=1; i<=n; i++)
//	{
//		ret = ret*i;
//	}
//	printf("%d\n",ret);
//	return 0;
//}




//#include <stdio.h>
//int fib(int n)
//{
//	if(n<=1)
//		return 1;
//	else
//		return n*fib(n-1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",fib(n));
//	return 0;
//}



//非递归
//#include <stdio.h>
//int fib(int n)
//{
//   int a = 1;
//   int b = 1;
//   int c = 1;
//   while(n>=3)
//   {
//   c = a+b;
//   a = b;
//   b = c;
//   n--;
//   }
//   return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",fib(n));
//	return 0;
//}





//斐波那契数 递归
//#include <stdio.h>
//int fib(int n)
//{
//	if(n<=2)
//		return 1;
//	else
//		return fib(n-1)+fib(n-2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",fib(n));
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char *str)
//{
//	assert(str != NULL);
//	if(*str =='\0')
//		return 0;
//	else
//		return (1+my_strlen(str+1));
//}
//int main()
//{
//	char const *str = "abcdef";
//	int ret = my_strlen(str);
//	printf("%d\n",ret);
//	return 0;
//}







//#include <stdio.h>
//void print(int n)
//{
//	if(n>9)
//	{
//		print(n/10);
//	}
//	printf("%d ",n%10);
//}
//int main()
//{
//	int num = 1234;
//	print(num);
//	return 0;
//}