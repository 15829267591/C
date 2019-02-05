#include <stdio.h>
int is_prime(int n)
{
  int i = 0;
  for(i=2; i<n; i++)
  {
	  if((n%i)==0)
	  {
		  return 0;
	  }
  }
  return 1;

}
int main()
{
	int num = 0;
	int count = 0;
	for(num=100; num<=200; num++)
	{
     if(is_prime(num)==1)
	 { 
		 count++;
	     printf("%d ",num);
	 }
	}
	printf("\ncount = %d\n ",count);
	return 0;
}










//#include <stdio.h>
//Bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz-1; i++)
//	{
//		int j = 0;
//		for(j=0; j<sz-1-i; j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//}
//PrintArr(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = {9,8,7,6,5,4,3,2,1,0};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	Bubble_sort(arr, sz);
//	PrintArr(arr, sz);
//	return 0;
//}
//
//







//杨辉三角
//#include <stdio.h>
//int main()
//{
//	int arr[100][100] = {0};
//	int i = 0;
//	
//	for (i=0; i<10; i++)
//	{
//		int j = 0;
//		for(j=0; j<10; j++)
//		{
//			if(j==0)
//			{
//				arr[i][j]=1;
//			}
//			if(i==j)
//			{
//				arr[i][j]=1;
//			}
//			if(i>1 && j>0)
//			{
//				arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
//			}
//		}
//	}
//		for (i=0; i<10; i++)
//	{
//		int j = 0;
//		for(j=0; j<=i; j++)
//		{
//			printf("%d ",arr[i][j]);
//			
//		}
//		printf("\n");
//	}
//
//	return 0;
//}








//#include <stdio.h>
//int main()
//{
//	int killer = 0;
//	for(killer='a'; killer<='d'; killer++)
//	{
//	 if((killer!='a')+(killer=='c')+(killer=='d')+(killer!='d')==3)
//		 printf("killer=%c\n", killer);
//	}
//	return 0;
//}
//




//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for(a=1; a<=5; a++)
//	{  
//		for(b=1;b<=5; b++)
//		{
//			for(c=1; c<=5; c++)
//			{
//				for(d=1; d<=5; d++)
//				{
//					for(e=1; e<=5; e++)
//					{
//						int i = 0;
//						int flag = 0;
//					   if((((b==2)+(a==3))==1)&&
//						  (((b==2)+(e==4))==1)&&
//						  (((c==1)+(d==2))==1)&&
//						  (((c==5)+(d==3))==1)&&
//						  (((e==4)+(a==1))==1))
//						{
//						   int ret = 0;
//						   ret|=1<<(a-1);
//						   ret|=1<<(b-1);
//						   ret|=1<<(c-1);
//						   ret|=1<<(d-1);
//						   ret|=1<<(e-1);
//						   for(i=0; i<5; i++)
//						   {
//							  
//							   if(((ret>>i)&1)==0)
//							   {	 
//								  flag = 1;
//							   }
//							   
//						   } 
//						   if(flag==0)
//						   printf("a=%d b=%d c=%d d=%d e=%d ", a,b,c,d,e);
//								
//						}
//
//							
//
//					}
//				}
//			}
//		}
//	}
//  return 0;
//}
//






//
////#include <stdio.h>
//Initarr(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		arr[i]= i+1;
//	}
//}
//PrintArr(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void ReserveArr(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz-1;
//while(left<right)
//{
//		
//	
//    int temp = arr[left];
//	    arr[left] = arr[right];
//	 arr[right] = temp;
//	left++;
//	right--;
//}
//
//}
//EmptyArr(int arr[],int sz)
//{
//	memset(arr, 0,sz*sizeof(arr[0]));
//	///*int i = 0;
//	//for(i=0; i<sz; i++)
//	//{
//	//	arr[i] = 0;
//	//}*/
//}
//int main ()
//{
//	int arr[10];
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	Initarr(arr, sz);
//	PrintArr(arr, sz);
//	ReserveArr(arr, sz);
//    PrintArr(arr, sz);
//	EmptyArr(arr, sz);
//	PrintArr(arr, sz);
//	return 0;
//}
//









//九九乘法表
//#include <stdio.h>
//void print_table(int n)
// {
//	 int i = 0;
//	 for(i=1; i<=n; i++)
//	 {
//		 int j = 0;
//		 for(j=1; j<=i; j++)
//		 {
//			 printf("%d*%d=%d ",i,j,i*j);
//		 }
//		 printf("\n");
//
//	 }
// }
//int main ()
//{
//	int line = 0;
//	scanf("%d",&line);
//	 print_table(line);
//		
//	return 0;
//}
//















//#include <stdio.h>
//int  binary_arr(int arr[], int key, int sz)
// {
//     int left = 0;
//	 int right = sz-1;
//	 
//	 while(left<=right)
//	 {
//		 int mid = left+(right-left)/2;
//		 if(arr[mid] == key)
//		 {
//			 return mid;
//		 }
//		 else if(arr[mid]<key)
//		 {
//		  left =mid+1;
//		 }
//		 else
//		 {
//			 right = mid-1;
//		 }
//	 }
//	 return 0;
// }
//int main()
//{
//	int arr[] = {0,1,2,3,4,5,6,7,8,9};
//	int key = 7;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int ret = binary_arr(arr, 7, sz);
//	if(ret == 0)
//	{
//		printf("找不到");
//	}
//	else
//		printf("找到了：%d", ret);
//	return 0;
//}
//
//












//#include <stdio.h>
//int is_leap_year(int year)
//{
//return(( year%4==0 && year%100!=0)||(year%400==0));
//}
//int main ()
//{
//	int year  = 0;
//	int count = 0;
//	for(year=1000; year<=2000; year++)
//	{
//	if(is_leap_year(year)==1)
//	{
//		count++;
//		printf("%d ",year);
//	}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}
//
//









//#include <stdio.h>
//#include <math.h>
//int is_prime(int n)
//{
//	//只要实现判断是否为素数的功能
//
//	    int i = 0;
//		for(i=2; i<=sqrt(n); i++)
//		{
//			if((n%i)==0)
//			{
//				return 0;
//			}
//		}
//		return 1;
//}
//int main ()
//{
//	int i = 0;
//	int count = 0;
//	for(i=100; i<200; i++)
//	{
//		if(is_prime(i)==1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}