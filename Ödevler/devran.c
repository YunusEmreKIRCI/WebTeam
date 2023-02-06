#include <stdio.h>
#include <stdlib.h>
struct node
{
    int Value1;
    struct node *link;
};
void print_linkedlist(struct node *head)
{
    struct node *doesExist = NULL;
    doesExist=head;
    while(doesExist!=NULL)
    {
        printf("%d ",doesExist->Value1);
        doesExist = doesExist->link;
    }

}
void Insert_End_Of_The_List(struct node *head,int value)
{
    struct node *ptr,*LastNode = NULL;

    LastNode=(struct node *)malloc(sizeof(struct node));
    LastNode->Value1=value;
    LastNode->link=NULL;

    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = LastNode;

}
void Insert(struct node *head,int value)
{
    int count,select =0;
    struct node *oldNode,*ptr,*newNode = NULL;

    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->Value1=value;
    newNode->link=NULL;

    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->link;
    }

    int mid = count/2;

    while(head!=NULL)
    {
        if(select==mid)
        {
            oldNode->link=newNode;
            newNode->link=head;
            break;
        }
        select++;
        oldNode=head;
        head = head->link;
    }

}
void Delete_Node(struct node *head,int value)
{
    struct node *ptr=NULL;
    ptr=head;

    while(ptr!=NULL)
    {
        if(ptr->Value1==value)
        {
            ptr=NULL; // yapilacak
            break;
        }
        ptr=ptr->link;
    }

}

int main()
{
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->Value1=45;
    head->link=NULL;

    struct node *another=NULL;
    another=(struct node *)malloc(sizeof(struct node));
    another->Value1=30;
    another->link=NULL;

    head->link=another;

    another=(struct node *)malloc(sizeof(struct node));
    another->Value1=15;
    another->link=NULL;

    head->link->link = another;



    Insert_End_Of_The_List(head,240);

    Delete_Node(head,240); // yapilacak

    Insert(head,44);
    print_linkedlist(head);

    free(another);
    free(head);

    return 0;
}
