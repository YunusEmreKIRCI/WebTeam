#include <stdio.h>
#include <stdlib.h>

int **tablo;
int array[10];
int main()
{

   tablo = (int **)malloc(10 * sizeof(int *));
   for(int i = 0; i < 10;i++){
    tablo[i] = (int *)malloc(10 * sizeof(int));

   }
   tabloolustur();
   kactanevarbul();
   enfazlaikisutun();


    return 0;
}



void tabloolustur(){
srand(time(0));

for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      *(*(tablo + i) + j) = rand()%2;
    }
}

for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      printf("%d ",tablo[i][j]);
    }
   printf("\n");
}

}


void kactanevarbul(){
printf("\n\n");

printf("-------------------\n");
for(int i = 0; i < 10; i++){
    int adet = 0;
    for(int j = 0; j < 10;j++){
     if(tablo[j][i] == 1){
        adet++;
     }
    }
     array[i] = adet;
     printf("%d ",array[i]);
}


}

void enfazlaikisutun(){

    int enbuyuk1 = array[0],index1 = 0;
    int enbuyuk2 = array[1],index2 = 1;
    if(enbuyuk1 < enbuyuk2){

        int gecici = enbuyuk1;enbuyuk1 = enbuyuk2;enbuyuk2 = gecici;index1 = 1;index2 = 0;

    }
     for(int i = 2; i < 10; i++){

       if(array[i] > enbuyuk1){

        enbuyuk1 = array[i];
        index1 = i;

       }

     }

     for(int i = 2; i < 10;i++){
      if(i == index1){
        continue;
      }else{
      if(array[i] > enbuyuk2 && array[i] <= enbuyuk1){
         enbuyuk2 = array[i];
         index2 = i;
      }
      }

     }

printf("\n");

printf("\n%d. sutunda %d adet bir var...\n",index1 + 1,array[index1]);
printf("%d. sutunda %d adet bir var...\n\n\n",index2 + 1,array[index2]);

int sayac = 0;
for(int i = 0; i < 10;i++){

    if(tablo[i][index1]){
       if(tablo[i][index2]){
        sayac++;
        printf("%d. satirda karsilasmislar...\n\n",i+1);
       }

    }
}
printf("%d kere karsilasma olmus....\n\n",sayac);

}
