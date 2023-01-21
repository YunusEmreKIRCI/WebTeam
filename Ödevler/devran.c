#include <stdio.h>
#include <stdlib.h>
int main()
{   int dizi[10][10];
    int sayac2;
    srand(time(NULL));
    int sutunIndex;
    int sutunIndex2;
    int maxdizieleman[10];
    int max=-1;
    int max2=-1;
    int sayac=0;
    int maxdizim[10][1];
    int maxdizim2[10][1];
    int arr[10];
    int k=0;
    for(int i=0;i<10;i++)
    {
        for(int k=0;k<10;k++)
        {
            dizi[i][k]=rand()%2;
            printf("%d ",dizi[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(int i=0;i<10;i++)
    {
        for(int k=0;k<10;k++)
        {
            if(dizi[k][i]==1)
            {
                sayac++;
            }
            if(k==9)
            {
                printf("%d ",sayac);
            }
        }
        maxdizieleman[i]=sayac;
        if(max<sayac)
            {
                max=sayac;
                sutunIndex=i;
            }
            for(int z=0;z<i;z++)
            {
                if(max2<maxdizieleman[z] && maxdizieleman[z]!=max)
                {
                   max2=maxdizieleman[z];
                   sutunIndex2=z;
                }
            }
       sayac=0;
    }
    printf("\n\nmax : %d",max);
    printf("\n\nmax2 : %d\n\n",max2);

    for(int i=0;i<10;i++)
    {
        maxdizim[i][1]=dizi[i][sutunIndex];
        maxdizim2[i][1]=dizi[i][sutunIndex2];
    }

    for(int i=0;i<10;i++)
    {
        printf("%d %d\n",maxdizim[i][1],maxdizim2[i][1]);
        if(maxdizim[i][1]==1 && maxdizim2[i][1]==1)
        {
            arr[k]=i;
            k++;
            sayac2++;
        }
    }
    printf("\n");
    for(int i=0;i<k;i++)
    {
        printf("%d. ",arr[i]+1);
    }
    printf("satirlarinda esitlerdir ve Toplamda %d tane esit ve 1 olduklari satir vardir.",sayac2);
    printf("\n");
    printf("\n");
    return 0;
}
