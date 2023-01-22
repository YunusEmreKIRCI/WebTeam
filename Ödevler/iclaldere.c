#include <stdio.h>
#include <stdlib.h>

//iclal dere

int main(){

int sayac;

int boyut;
printf("dizinin boyutunu girin :\n");
scanf("%d",&boyut);
int A[boyut];
int adet;

for(int i=0;i<boyut;i++){
    printf("\n %d. elemani girin : ",i+1);
    scanf("%d",&A[i]);
}

printf("\n");


for(int i=0;i<boyut;i++){
        sayac=1;
        for(int j=i+1;j<boyut;j++){
            if(A[i]==A[j]){
                sayac++;
                A[j]=-1;
            }
        }
        if(A[i]!=-1)
            printf("%d\t%d adet\n",A[i],sayac);
    }



}
