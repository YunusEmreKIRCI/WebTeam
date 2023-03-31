#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int addNode(int data)
{

    if(head==NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        tail->next = new;

        tail = new;
    }

    return 1;
}

int addNodeHead(int data)
{
    if(head==NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = head;

        head = new;
    }
}

int print()
{
    printf("Linked List: ");
    struct node *index = head;
    while(index!=NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }
    printf("\n");
    return 1;
}

int delete(int data)
{

    struct node *prev = NULL;
    struct node *index = head;

    if(head==NULL)
    {
        printf("Linked List is empty \n");
        return 1;
    }

    if(head->data==data)
    {
        struct node *t = head;
        head = head->next;
        free(t);
        return 1;
    }

    while(index!=NULL && index->data!=data)
    {
        prev = index;
        index = index->next;
    }

    if(index==NULL)
    {
        printf("Data not found. \n");
        return 1;
    }

    prev->next = index->next;

    if(tail->data==data)
    {
        tail = prev;
    }

    free(index);

    return 1;
}
// araya eleman ekleme fonksiyonu (verilen degerin yanina ekleme yapar)
void insertAfter(struct node* prevNode, int newData)
{
    if(prevNode==NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct node *newNode=(struct node*) malloc(sizeof(struct node)); //yeni dugum icin bellek alani ayriliyor.

    newNode->data=newData;
    newNode->next=prevNode->next;
    prevNode->next = newNode;

}


int main()
{
    int i;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = 15;
    new->next = NULL;
    int choice;
    head = tail = new;
    print();
    //sona eleman ekleyelim
    addNode(11);
    print();
    //araya eleman ekleyelim-onune eklemek istedigimiz sayiyi da girmemiz gerekir
    printf("\nType the data you want to add: ");
    scanf("%d",&choice);
    insertAfter(head, choice);
    print();
    // bastaki elemaný silelim
    delete(15);
    print();


    return 1;
}
