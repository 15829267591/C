#include <stdio.h>
int main()
{
 int i = 0;
 double sum = 0;
 int p =1;
 for(i=1; i<101; i++)
 {
	 sum = sum+p*(1.0/i);
	 p=-1*p;
 }
 printf("%lf\n", sum);
 return 0;
}










//
//
//
////将两个数组内容交换
//#include <stdio.h>
//int main()
//{
//	int arr1[3] = { 1,2,3};
//	int arr2[3] = { 5,6,7};
//	int sz =sizeof(arr1)/sizeof(arr1[0]);
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//			
//	}
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr1[i]);
//		
//	}
//	printf("\n");
//
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr2[i]);
//	
//	}
//	return 0;
//    
//}

















//
////求两个数的最大公约数
//#include <stdio.h>
//int main()
//{
//	int m = 18;
//	int n = 24;
//	while(m%n != 0)
//	{
//		int temp = m%n;
//		m = n;
//		n = temp;
//	}
//	printf("%d\n", n);
//	return 0;
//
//}
















//将三个数从大到小排列

//#include <stdio.h>
//
//Swap(int*px, int*py)
//{
//	int temp = 0;
//	temp = *px;
//	*px = *py;
//    *py = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	if(a<b)
//	{
//      Swap(&a,&b);
//	}
//	if(a<c)
//	{
//     Swap(&a, &c);
//	}
//	if(b<c)
//	{
//     Swap( &b, &c);
//	}
//  printf("%d %d %d\n", a,b,c);
//  return 0;
//}





























//#include <stdio.h>
//int main()
//{
//	int arr[]={-1,-2,-3,-4,-5,-9,1};
//    int max = arr[0];
//	int i=0;//要注意初始化
//	for( i=1; i<sizeof(arr)/sizeof(arr[0]); i++)
//	{
//      if(arr[i]>max)
//	  {
//		  max=arr[i];
//	
//	  }
//	}
//	printf("%d\n", max);
//	return 0;
//}