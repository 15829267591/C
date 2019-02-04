#include<stdio.h>


 void printd(int n)
 { 
  if(n >=10)
	  printd(n/10);
  printf("%d ",n%10);
 }

int main()
{ printd(123);
   printf("\n");
}
//#include<stdlib.h>
//
//#define N 8
//char board[N+2][N+2];
//void init ()
//{ 
//int i, j;
//for(i = 0;i< N+2; i++)
//{ 
// for(j=0; j<N+2; j++)
// { 
//  if(i==0|| i==N+1||j==0||j==N+1)
//	  board[i][j] = '#';
//  else
//	  board[i][j] = ' ';
// }
//}
//}
//
//void show()
//{ 
//int i, j;
//for(i=0; i<N+2; i++)
//{ 
// for(j=0;j<N+2; j++)
//	 printf("%c",board[i][j]);
// printf("\n");
//}
//}
//
//int check(int i, int j)
//{ 
// int  ni = i;
// int nj =j;
// int ret = 1;
// while(ret && board[ni][nj]!='#')
// { 
//	 if(board[ni][nj] == '#')
//		 ret = 0;
//	 ni-=1;
//	 nj-=1;
// }
// ni = i;
// nj = j;
// while(ret && board[ni][nj]!='#')
// { 
//	 if(board[ni][nj] == '#')
//		 ret = 0;
//	 ni-=1;
//	
// }
// ni = i;
// nj = j;
// while(ret && board[ni][nj]!='#')
// { 
//	 if(board[ni][nj] == '#')
//		 ret = 0;
//	 ni-=1;
//	 nj+=1;
//	
// }
// return  ret;
//
//}
//
//void find (int line)
//{ 
// if(line>N)
// { 
// show();
// }
// else{
//	 int j;
// for(j=1;j<=N;j++)
// {
//	 if(check(line,j)){
// board[line][j] = '*';
// find(line+1);
// board[line][j] = ' ';
// } 
// }
//}
//}
//int main()
//{
//	init();
//	find(1);
//	show();
//
//return 0;
//} 
