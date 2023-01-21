#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sayac1=0;
    int sayac0=0;
    srand(time(0));
    int dizi[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            dizi[i][j]=rand()%2;
            if(dizi[i][j]){

                sayac1++;
            }

        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
        printf("%d ",dizi[i][j]);
        printf("\n");
    }
    printf("\n-----------------------\n");


    int sutun1=0,sutun2=0,maxsayac=0;
    for(int i=0;i<10;i++){
        int sayac=0;
        for(int j=0;j<10;j++){
            sayac=sayac+dizi[j][i];
        }
        if(sayac>maxsayac){
            maxsayac=sayac;
            sutun2=sutun1;
            sutun1=i;
        }
        else if(sayac==maxsayac && i!=sutun1){
            sutun2=i;
            break;
        }
    }
    int sayac=0;
    for(int i=0;i<10;i++){
        if(dizi[i][sutun1]==1 && dizi[i][sutun2]==1){
            sayac++;
        }
    }
    printf("En cok 1 olan 2 sutun %d ve %d'dir\nToplamda %d satirda 2 sutun da 1'dir bunlar:\n",sutun1+1,sutun2+1,sayac);
     printf("-----------------------\n");

    for(int i=0;i<10;i++){
        if(dizi[i][sutun1]==1 && dizi[i][sutun2]==1){
            sayac++;
            printf("%d.satir: %d.sutun ve %d.sutun\n",i+1,sutun1+1,sutun2+1);
        }
    }
     printf("\n-----------------------\n");

    printf("Matristeki 1 sayisi=%d, 0 sayisi=%d",sayac1,100-sayac1);
     printf("\n-----------------------\n");

    return 0;
}
