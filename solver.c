#include <stdio.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc,char** argv)
{
$ ./solver.sh 1-0-3-1=15-1-21
int number1 = atoi(argv[1]);
char sign = argv[2][0];
int number2 = atoi(argv[3]);
int result  = atoi(argv[5]);


int prob[10][10] = 
                 {
                 {0, 2, 3, 5, 6, 8, 9, 0, 0, 0},
		 {1, 4, 7, 0, 0, 0, 0, 0, 0, 0},
		 {2, 0, 3, 5, 6, 8, 9, 0, 0, 0},
		 {3, 0, 2, 4, 5, 6, 7, 8, 9, 0},
		 {4, 1, 3, 5, 9, 0, 0, 0, 0, 0},
		 {5, 0, 2, 3, 4, 6, 8, 9, 0, 0},
		 {6, 0, 2, 3, 5, 8, 9, 0, 0, 0},
		 {7, 1, 3, 4, 0, 0, 0, 0, 0, 0},
		 {8, 0, 2, 3, 5, 6, 9, 0, 0, 0},
		 {9, 0, 2, 3, 4, 5, 6, 8, 0, 0}
                 };

double mov[10][10][2] = 
                 {
                 {{0,0},{100,100},{2,1},{2,1},{100,100},{2,1},{1,1},{100,100},{0,1},{1,1}},
		 {{100,100},{0,0},{100,100},{100,100},{0,2},{100,100},{100,100},{0,1},{100,100}, {100,100}},
		 {{1,2},{100,100},{0,0},{1,1},{100,100},{2,2},{1,2},{100,100},{0,2},{1,2}},
		 {{1,2},{100,100},{1,1},{0,0},{2,1},{1,1},{1,2},{2,0},{0,2},{0,1}},
		 {{100,100},{2,0},{100,100},{1,2},{0,0},{1,2},{100,100},{100,100},{100,100},{0,2}},
		 {{1,2},{100,100},{2,2},{1,1},{2,1},{0,0},{0,1},{100,100},{0,2},{0,1}},
		 {{1,1},{100,100},{2,1},{2,1},{100,100},{1,0},{0,0},{100,100},{0,1},{1,1}},
		 {{100,100},{1,0},{100,100},{0,2},{1,2},{100,100},{100,100},{0,0},{100,100},{100,100}},
		 {{1,0},{100,100},{2,0},{2,0},{100,100},{2,0},{1,0},{100,100},{0,0},{1,0}},
		 {{1,1},{100,100},{2,1},{1,0},{2,0},{1,0},{1,1},{100,100},{0,1},{0,0}}
                 };

int i,j,k,pick,put;

for (i=0; i<10; i++)
  for(j=0; j<10; j++)
    for(k=0; k<10; k++)
    {
     if(prob[number1][i]+prob[number2][j]==prob[result][k])
     {
      pick = mov[number1][prob[number1][i]][0] + mov[number2][prob[number2][j]][0] + mov[result][prob[result][k]][0];
      put  = mov[number1][prob[number1][i]][1] + mov[number2][prob[number2][j]][1] + mov[result][prob[result][k]][1];
        if(sign=='-')put++;
      switch(pick)
      {
      case 1:
       if(put==1) 
       {   
        printf("%s %d + %d = %d    %s[ correct ]%s   [ one move  ]\n",KYEL,prob[number1][i],prob[number2][j],prob[result][k],KGRN,KRED);
       }
      break;
     case 2:
      if(put==1||put==2)
     {  
      printf("%s %d + %d = %d    %s[ correct ]%s   [ two moves ]\n",KYEL,prob[number1][i],prob[number2][j],prob[result][k],KGRN,KCYN);   
     }    
     break;
     }

     }  // end of if + ==

    if(prob[number1][i]-prob[number2][j]==prob[result][k])
    { 
     pick = mov[number1][prob[number1][i]][0] + mov[number2][prob[number2][j]][0] + mov[result][prob[result][k]][0];
     put  = mov[number1][prob[number1][i]][1] + mov[number2][prob[number2][j]][1] + mov[result][prob[result][k]][1];
      if(sign=='+')pick++;
      switch(pick)
      {
      case 1:
      if(put==1) 
      {   
      printf("%s %d - %d = %d    %s[ correct ]%s   [ one move  ]\n",KYEL,prob[number1][i],prob[number2][j],prob[result][k],KGRN,KRED);
      }
      break;
     case 2:
     if(put==1||put==2)
     {  
      printf("%s %d - %d = %d    %s[ correct ]%s   [ two moves ]\n",KYEL,prob[number1][i],prob[number2][j],prob[result][k],KGRN,KCYN); 
      }    
     break;
    }  


   }
   }



return 0;
}
