#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

// Stack(Yığın) Lifo (last in first out) son giren ilk çıkar mantığı vardır. çamaşırlar ile benzetilebilir.
// bellek yönetiminde sayfaların swap(takas) işlemlerinde. uygulamaların geri al işlemlerinde. tarayıcıların geri al butonunda.

struct node{

int number;
struct node* ptr;

};

typedef struct node AA;

AA *Head =  NULL;

void addData(int data){

    if(Head == NULL){

     AA* newNode = (AA*)malloc(sizeof(AA));
     newNode->number = data;
     newNode->ptr = NULL;
     Head = newNode;

    }else{

     AA* newNode = (AA*)malloc(sizeof(AA));
     newNode->number = data;
     newNode->ptr = Head;
     Head = newNode;

    }


}

void printStack(){

    if(Head == NULL){
      printf("Stack bos. Eleman yok.\n");

    }else{
          AA* Temp = (AA*)malloc(sizeof(AA));
          Temp = Head;
          while(Temp != NULL){
          printf("%d-",Temp->number);
          Temp = Temp->ptr;
          }

    }

}

void searchStack(int data){
    int i = 1;
    if(Head == NULL){
      printf("Stack bos. Eleman yok.\n");

    }else{
          AA* Temp = (AA*)malloc(sizeof(AA));
          Temp = Head;
          while(Temp != NULL){
          if(Temp->number == data){
           printf("Aranan eleman %d. sirada...\n\n",i);
          }
          Temp = Temp->ptr;
          i++;
          }
          if(i == 1){
            printf("Aranan eleman yok...");
          }

    }

}

void popData(){

  if(Head == NULL){
    printf("Stack bos. Eleman yok.\n");
    return;
  }else{
    AA* Temp = Head;
    Head = Head->ptr;
    free(Temp);
  }


}

int main()
{


while(true){

   int select = menu();
   if(select == 5){
     printf("Sistemden cikiliyor...");
     sleep(2);
     break;
   }else if(select == 4){
    printf("Aramak istediginiz degeri giriniz: ");
    int dt;
    scanf("%d",&dt);

    searchStack(dt);

   }else if(select == 3){

    printStack();

   }else if(select == 2){

    popData();

   }else{
    printf("Eklemek istediginiz degeri giriniz: ");
    int dt;
    scanf("%d",&dt);
    addData(dt);

   }

}


return 0;





return 0;
}

int menu(){
  int select;
  do{
     printf("\n1-Eleman ekle\n2-Yigindan eleman cikar\n3-Elemanlarin hepsini yazdir\n4-Eleman ara\n5-Sistemden cik\n\nYapacaginiz islemi seciniz: ");
     scanf("%d",&select);
     if(select < 1 || select > 5){
        printf("\nDogru bir secim giriniz...\n");
     }

  }while(select < 1 || select > 5);
  system("cls");
  printf("\n");
  return select;
}
