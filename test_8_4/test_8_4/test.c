//#include <stdio.h>
//int main()
//{
//	int m = 1999;
//	int n = 2299;
//	int count = 0;
//	int temp = m^n;
//	 while (temp)
//	 {
//		 temp = temp &(temp-1);
//			 count++;
//	 }
//	 printf("%d\n",count);
//
//	return 0;
//}









//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int i = 0;
//	for(i=31; i>=1; i-=2)
//	{
//        printf("%d ",(num>>i)&1);
//	}
//	printf("\n");
//	for(i=30; i>=0; i-=2)
//	{
//		printf("%d ", (num>>i)&1);
//	}
//	return 0;
//
//}









//#include <stdio.h>
//int main()
//{
//	int num = -1;
//	int count = 0;
//	while (num)
//	{
//		num = num&(num-1);
//			count++;
//	}
//	printf("%d\n",count);
//	return 0;
//}





//#include <stdio.h>
//int main ()
//{
//  int i = 0;
//  int num =15;
//  int count = 0;
//  
//  
//	  for(i=0; i<32; i++)
// 	  {
//           if(((num>>i)&1)==1)
//			   count++;
//	  }
//	  
//  
//  printf("%d\n", count);
//
//	return 0;
//}








//#include <stdio.h>
//int binary_search(int arr[],int key,int sz)
//{
//int left = 0;
//int right = sz-1;
//
//while(left<=right)
// {
//  int mid= left+(right-left)/2;
//if(arr[mid] == key)
//  {
//      return mid;
//  }
//else if(arr[mid]<key)
//  {
//	left = mid+1;
//  }
//else 
//  {
//	right = mid-1;
//  }
// }
//return -1;
//}
//int main()
//{ 
//	int arr[] = {1,2,3,4,5,6,7,8,9};
//	int key = 7;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int ret = binary_search(arr,key,sz );
//	if(ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("找到了：%d\n", ret);
//	}
// return 0;
//}