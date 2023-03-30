#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>


struct node{

   int data;
   struct node* ptr;

};

typedef struct node AA;


AA* Head = NULL;
AA* Last = NULL;

void printQueue(){

if(Head == NULL){
    printf("Kuyruk bos...\n");
}else{

AA* temp = Head;
while(temp != NULL){
    printf("%d-",temp->data);
    temp = temp->ptr;
}

}

}


void adddata(int dt){

   AA* newNode = (AA*)malloc(sizeof(AA));
   newNode->data = dt;

if(Head == NULL){

   newNode->ptr = NULL;
   Head = newNode;
   Last = newNode;

}else if(Head == Last){

   if(Head->data >= dt){
     Head->ptr =  newNode;
     newNode->ptr = NULL;
     Last = newNode;

   }else{

    newNode->ptr = Head;
    Last = Head;
    Head = NULL;


   }

}else if(dt >= Head->data){

   newNode->ptr = Head;
   Head = newNode;

}else{

  AA* ileriGiden = (AA*)malloc(sizeof(AA));
  AA* Geridengelen = (AA*)malloc(sizeof(AA));
  ileriGiden = Head->ptr;
  Geridengelen = Head;

  while(ileriGiden != NULL){
    if(dt >= ileriGiden->data){

        Geridengelen->ptr = newNode;
        newNode->ptr = ileriGiden;
        return;

    }
    ileriGiden = ileriGiden->ptr;
    Geridengelen = Geridengelen->ptr;

  }

  Geridengelen->ptr = newNode;
  newNode->ptr = NULL;
  Last = newNode;

}


}


void search(int TT){

   AA* index = Head;
   if(Head == NULL){
     printf("Kuyrukta eleman yok...\n");
     return;
   }
   int i = 1,a = 9;
    while(index != NULL){
    if(index->data == TT){
        printf("Aranan deger %d. sirada-",i);
        a = 10;
    }
    index = index->ptr;
    i++;
   }
   printf("\n");
   if(a == 9){
    printf("Aranan deger kuyrukta yok...");
   }

}


void takeOutData(){

   if(Head == NULL){
     printf("Kuyrukta eleman yok...\n");
   }else{

   if(Head == Last){
    AA* newNode = Head;
    free(newNode);
    Head = NULL;
    Last = NULL;

   }else{
    AA* newNode = Head;
    Head = Head->ptr;
    free(newNode);

   }

   }


}


int main(){


while(true){

   int select = menu();
   if(select == 5){
     printf("Sistemden cikiliyor...");
     sleep(2);
     break;
   }else if(select == 4){

    printf("Arayacaginiz degeri giriniz: ");
    int dt;
    scanf("%d",&dt);

    search(dt);

   }else if(select == 3){

   printQueue();

   }else if(select == 2){


    takeOutData();

   }else{

    printf("Eklemek istediginiz degeri giriniz: ");
    int dt;
    scanf("%d",&dt);
    adddata(dt);

   }

}


return 0;

}

int menu(){
  int select;
  do{
     printf("\n1-Kuyruga eleman ekle\n2-Kuyruktan eleman cikar\n3-Elemanlarin hepsini yazdir\n4-Eleman ara\n5-Sistemden cik\n\nYapacaginiz islemi seciniz:");
     scanf("%d",&select);
     if(select < 1 || select > 5){
        printf("\nDogru bir secim giriniz...\n");
     }
  }while(select < 1 || select > 5);
  system("cls");
  printf("\n");

  return select;
}
