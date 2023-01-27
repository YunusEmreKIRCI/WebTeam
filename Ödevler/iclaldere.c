#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{

srand(time(NULL));
int bir,iki,konum1,konum2;
int **A;
int *B;
B=(int*)calloc(10,sizeof(int));
A=(int**)malloc(10*sizeof(int*));

for(int i=0;i<10; i++){
    *(A+i)=(int*)malloc(10*sizeof(int));
        for(int j=0;j<10;j++){
            A[i][j]=rand()%2;
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n");


for(int j=0;j<10;j++)
{
    for(int i=0;i<10;i++)
    {
        if(A[i][j]==1)
        {
            B[j]=B[j]+1;
        }
    }
}

for(int i=0;i<10;i++){
    printf("%d ",B[i]);}

    printf("\n");

bir=B[0];
iki=B[0];
for(int i=0;i<10;i++){
    if(B[i]>bir){
        bir=B[i];
    }
}

for(int i=0;i<10;i++){
    if(B[i]==bir)
        konum1=i;
}

for(int i=0;i<10;i++){
    if(B[i]<bir && B[i]>iki){
        iki=B[i];
    }
}

for(int i=0;i<10;i++){
    if(B[i]==iki){
        konum2=i;
    }
}

printf("\n");

printf("\n%d. sutunda toplam %d adet bir var\n\n",konum1+1,bir);
for(int i=0;i<10;i++){
    if(A[i][konum1]==1){
        printf("%d. satir \n",i+1);
    }
}
printf("\n");

printf("%d. sutunda toplam %d adet bir var\n\n",konum2+1,iki);
for(int i=0;i<10;i++){
    if(A[i][konum2]==1){
        printf("%d. satir \n",i+1);
    }
}

free(A);
free(B);
    return 0;
}


