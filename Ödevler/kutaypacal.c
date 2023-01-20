#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int dizi[10][10],sayac[10],en1=0,en2=1,sayac2=0;
    for(int satir=0; satir<10; satir++)
    {
        printf("\n\n");
        for(int sutun=0; sutun<10; sutun++)
        {
            dizi[satir][sutun]=rand()%2;
            printf("%d ",dizi[satir][sutun]);
        }
    }
    printf("\n*******************\n");
    for(int sutun=0; sutun<10; sutun++)
    {
        sayac[sutun]=0;
        for(int satir=0; satir<10; satir++)
        {
            if(dizi[satir][sutun]==1)
            {
                sayac[sutun]++;
            }
        }
    }
    for(int sutun=0; sutun<10; sutun++)
        printf("%d ",sayac[sutun]);
    for(int sutun=2; sutun<10; sutun++)
    {
        if(sayac[en1]<sayac[sutun])
        {
            if(sayac[en1]<sayac[en2])
                en1=sutun;
            else
                en2=sutun;
            continue;
        }
    }
    printf("\n\nEn fazla 1'i bulunduran sutunlar %d. ve %d. sutunlardir.\n\nSirasiyla %d ve %d tane 1 bulundururlar.\n\n",en1+1,en2+1,sayac[en1],sayac[en2]);
    for(int satir=0; satir<10; satir++)
    {
        printf("\n\t%d %d \t",dizi[satir][en1],dizi[satir][en2]);
        if(dizi[satir][en1]==dizi[satir][en2])
        {
            printf("%d. satirda iki sutun da 1 degerine sahiptir.",satir+1);
            sayac2++;
        }
    }
    printf("\n\n%d kez 1 degerleri denk gelmistir.\n",sayac2);
    return 0;
}
