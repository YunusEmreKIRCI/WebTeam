#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
 {
    int veri;
    struct dugum *next;
} Node;

typedef struct
 {
    int once;
    Node *next;
} onceliksirasi;

int kontrolet(onceliksirasi *x)
{
    if (x->next==NULL)
 {
        printf("kuyruk bos:");
        return -1;
    }

    int veri=x->next->veri;
    Node *temp=x->next;
    x->next=x->next->next;
    free(temp);
    return veri;
}
void gecis(onceliksirasi *x, int veri)
{
    Node *yenidugum=(Node *) malloc(sizeof(Node));
    yenidugum->veri=veri;

    if (x->next==NULL)
 {
        x->next=yenidugum;
        yenidugum->next=NULL;
    } else
 {
        Node *temp=x->next;
        Node *bas=NULL;
        while (temp!=NULL && temp->veri>=veri)
 {
            bas=temp;
            temp=temp->next;
        }
        if (bas == NULL)
 {
            x->next=yenidugum;
        } else
{
            bas->next=yenidugum;
        }
        yenidugum->next=temp;
    }
}
int main()

 {
    onceliksirasi x={0,NULL};
    gecis(&x,4);
    gecis(&x,6);
    gecis(&x,9);
    gecis(&x,8);
    gecis(&x,2);

    printf("%d\n", kontrolet(&x));
    printf("%d\n", kontrolet(&x));
    printf("%d\n", kontrolet(&x));
    printf("%d\n", kontrolet(&x));
    printf("%d\n", kontrolet(&x));
    printf("%d\n", kontrolet(&x));

    return 0;
}
