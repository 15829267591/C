#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int arr[10] = {0};
   
	
   for(i=0; i<3; i++)
   { 
	   printf("���������룺");
	scanf("%s",arr);
    if(strcmp("123456",arr)==0)
	{
		printf("��½�ɹ�");
		break;

	}
	else
		printf("����������������룡");
   }
   if(i==3)
	   printf("�˳�����");

 return 0;

}









//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main ()
//{  
//	char arr1[] = "Tyoye Sivan";
//	char arr2[] = "###########";
//	int left = 0;
//	int right = strlen(arr1)-1;
//	while(left<=right)
//	{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//    system("cls");
//	printf("%s",arr2);
//	Sleep(1000);
//	left++;
//	right--;          
//
//	}
//
//  return 0;
//
//}









//������
//#include <stdio.h>
//int main()
//{
//  int ch = 0;
//  int count = 0;
//  while((ch = getchar())!= EOF)
//  {
//	  if((ch== '}')&& (count==0))
//	  {
//	  printf("��ƥ��");
//		  return 0;
//	  }
//	  if((ch=='}')&& (count!=0))
//		  count--;
//	  else if (ch=='{')
//		  count++;
//  }
//  if(count==0)
//	  printf("ƥ��");
//  else
//    printf("��ƥ��");
//  return 0;
//}
//
//







//
//#include <stdio.h>
//int main()
//{
//   int ch = 0;
//   int count = 0;
//   while((ch = getchar())!= EOF)
//   {
//	   if(ch=='{')
//	   
//	    count++;
//	   
//	   else if(ch == '}')//ע����==
//	   
//	    count--;
//	   
//  
//   }
//   if(count==0)
//
//     printf("ƥ��");
//   
//   else
//  
//	   printf("��ƥ��");
//   return 0;
//
//}










// Sn = a+aa+aaa+aaaa+aaaaa
//#include <stdio.h>
//int main()
//{
//   int a = 0;
//   int n = 0;
//   
//    int i = 0;
//	int temp = 0;
//	int sum = 0;
//	scanf("%d %d", &a,&n);
//	for(i=0; i<n; i++)
//	{ 
//		
//		temp = temp*10+a;
//	    sum = sum +temp;
//
//	}
//	printf("Sum=%d\n ", sum);
//	return 0;
//
//}
//
















////��ӡˮ�ɻ���
//#include <stdio.h>
//#include <math.h>
//
//int main ()
//{
//  int i = 0;
//  for(i=1; i<100000; i++)
//  {
//	  //�����ж���λ
//    int count = 1;
//	int temp = i;
//	int sum = 0;
//	while(temp>=10)
//	{
//          count++;
//		  temp = temp/10;
//		  
//	}
//	//����ÿһλ���������Ҽ���η���
//	temp = i;
//	while(temp)
//	{
//		sum = sum + pow(temp%10 ,count);
//		temp = temp/10;
//
//
//	}
//
//	if(i == sum)
//	{
//		printf("%d ", i);
//
//	}
//    
//  }
//  return 0;
//}























//��ӡ����ͼ��
//#include <stdio.h>
//int main ()
//{
//    int line = 0;
//		int i = 0;
//	scanf("%d", &line);
//
//	for(i=0; i<line; i++)
//	{
//      //��ӡ�ո�
//		int j = 0;
//		for(j=0; j<line-1-i; j++)
//		{
//            printf(" ");
//		}
//	  //��ӡ*
//		for(j=0; j<2*i+1; j++)
//		{
//               printf("*");
//		}
//     printf("\n");
//
//	}
//	//��ӡ�°벿��
//  for(i=0; i<line-1; i++)
//  {
//	  int j = 0;
//	for(j=0; j<i+1; j++)
//	{
//		printf(" ");
//
//	}
//	for(j=0; j<2*(line-1-i)-1; j++)
//	{
//
//      printf("*");
//	}
//	printf("\n");
//
//  }
//  return 0;
//
//}















//#include <stdio.h>
//int main()
//{
//  int i = 0;
//  int count = 0;
//  for(i=1; i<=100; i++)
//  {
//     if((i%10) == 9)
//	 {
//	  count++;
//	 }
//	 if((i/10)== 9)
//	 {
//		 count++;
//	 }
//  }
//  printf("%d\n", count);
//  return 0;
//
//}
