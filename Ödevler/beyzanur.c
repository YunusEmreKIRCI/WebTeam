
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int sayac=0,sayac2=0,a=0,b=0;
    int en1=0, en2=0;
    int **A=(int **)malloc(10*sizeof(int*));
    for(int i=0; i<10; i++)
    {
        A[i]=(int *)malloc(10*sizeof(int));
    if(A==NULL)
         {
             printf("bellekten yer alýnamadý");
         }
     else
    {
        for(int j=0; j<10; j++)
        {
            A[i][j]=rand()%2;
            printf("%4d",A[i][j]);
        }
    }
        printf("\n");
    }

    for(int j=0; j<10; j++)
    {
        for(int i=0; i<10; i++)
        {
            if(A[i][j]==1)
                sayac++;
        }
            if(a<sayac)
            {
                a=sayac;
                en1=j+1;
            }
            sayac=0;
    }

     printf("%d sutunu 1. en fazla 1'e sahip sutundur. %d tane 1 baririndirir.\n",en1,a);

    for(int j=0; j<10; j++)
    {
        for(int i=0; i<10; i++)
        {
            if(A[i][j]==1)
               sayac2++;
        }
          if(a!= sayac2)
          {
              if(b<sayac2)
            {
                b=sayac2;
                en2=j+1;
            }
          }

            sayac2=0;
        }

     printf("%d sutunu 2. en fazla 1'e sahip sutundur. %d tane 1 baririndirir.\n",en2,b);

        free(A);

        return 0;
    }
