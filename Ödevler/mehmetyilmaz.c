#include <stdio.h>
#include <stdlib.h>

int main()
{

   int A[10][10];
   int i,j,m=0,n=0,sayac=0;
   int B[10];
   srand(time(0));

   for(i=0;i<10;i++)
   {
    for(j=0;j<10;j++)
       {
          A[i][j]=rand()%2;
       }
   }
   for(i=0;i<10;i++)
   {
       for(j=0;j<10;j++)
       {
          printf("%d",A[i][j]);
       }
       printf("\n");
   }

   for(j=0;j<10;j++)
   {
       for(i=0;i<10;i++)
       {
        if(A[i][j]==1)
            {
                sayac++;
            }
       }
    printf("%d. sutunda %d tane 1 vardir\n",j+1,sayac);
    B[j]=sayac;
    sayac=0;
   }
   int temp=B[0];
   for(i=0;i<10;i++)
   {
       if(B[i]>temp)
       {
           temp=B[i];
           m=i;
       }
   }
   printf("en fazla 1 %d. sutunda vardir ve %d kadar vardir\n",m+1,temp);

   int temp2=B[0];
   for(i=0;i<10;i++)
   {

    if(i!=m)
    {
      if(B[i]>temp2 && B[i]<=temp)
       {
           temp2=B[i];
           n=i;
       }

    }

   }
   printf("ikinci en fazla 1 %d. sutunda vardir ve %d kadar vardir\n",n+1,temp2);





      int sayac2=0;
      for(i=0;i<10;i++)
      {
          if(A[i][m]==A[i][n])
          {
              printf("%d. satirda her iki sutunda da 1 vardir\n",i+1);
          }
      }




    return 0;
}
