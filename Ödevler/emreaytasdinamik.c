#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **table;
int *number;

void dotable(){


   srand(time(NULL));
   
   for(int i = 0; i < 10 ; i++){
   
   for(int j = 0; j < 10 ;j++){
    
    table[i][j] = rand()%2;
   
    printf("%d ",table[i][j]);
   
   }
   
   printf("\n");
   
   }

}

void onenumber(){

    printf("-------------------\n");
    for(int i = 0 ; i < 10 ; i++){
      int sayi = 0;
      for(int j = 0; j < 10 ; j++){
      if(table[j][i] == 1){
        sayi++;
      }                        

      }
      printf("%d ",sayi);
      number[i] = sayi;

    }

    printf("\n-------------------\n\n");



}

int main(){

        
    number = (int *)malloc(10 * sizeof(int));
    
    int yy = 0;

    while (!number)
    {
          
      printf("Bellekten yer ayrilamadi...");
           yy++;
           number = (int *)malloc(10 * sizeof(int));
           number = (int *)malloc(10 * sizeof(int));
           if(yy == 100){
            free(number);
            printf("Sistemden cikiliyor...");
            exit(0);
        }
    }


   int yt = 0;
    table = (int**)malloc(10 * sizeof(int *));

    while (!table)
    {
            yt++;
            table = (int**)malloc(10 * sizeof(int *));
            if(yt == 100){
               free(number);
               free(table);  
               printf("Sistemden cikiliyor...");
               exit(0);  
            }
    }
    


    for(int i = 0; i < 10;i++){
        table[i] =  (int*)malloc(10 * sizeof(int));

        int yu = 0;
        while (!table[i])
    {
            yu++;
            table[i] =  (int*)malloc(10 * sizeof(int));
            if(yu == 100){

               free(number);
               free(table);  
               printf("Sistemden cikiliyor...");
               exit(0);  
            
            }
    
    
    }
 


    } 
    
    dotable();
    onenumber();
    maxverstappen();
    
    free(number);
    for(int i = 9; i >= 0;i--){
        free(table[i]);
    }     

    return 0;

}   


void maxverstappen(){

    int enbuyuk1 = number[0],index1 = 0;
    int enbuyuk2 = number[1],index2 = 1;
    if(enbuyuk1 < enbuyuk2){

        int gecici = enbuyuk1;enbuyuk1 = enbuyuk2;enbuyuk2 = gecici;index1 = 1;index2 = 0;

    }
     for(int i = 2; i < 10; i++){

       if(number[i] > enbuyuk1){

        enbuyuk1 = number[i];
        index1 = i;

       }

     }

     for(int i = 2; i < 10;i++){
      if(i == index1){
        continue;
      }else{
      if(number[i] > enbuyuk2 && number[i] <= enbuyuk1){
         enbuyuk2 = number[i];
         index2 = i;
      }

      }

     }

printf("\n");

printf("\n%d. sutunda %d adet bir var...\n",index1 + 1,number[index1]);
printf("%d. sutunda %d adet bir var...\n\n\n",index2 + 1,number[index2]);

int sayac = 0;
for(int i = 0; i < 10;i++){

    if(table[i][index1]){
       if(table[i][index2]){
        sayac++;
        printf("%d. satirda karsilasmislar...\n\n",i+1);
       }

    }
}
printf("%d kere karsilasma olmus...\n\n",sayac);

}


