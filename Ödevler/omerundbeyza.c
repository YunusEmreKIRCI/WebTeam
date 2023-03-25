#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct node { //Linked Listteki node'un aynısı
    int data;
    struct node *next;
} Node;

typedef struct { //Stack tanımlaması
    Node *top;
} Stack;

void push(Stack *s, int data) { //Stack'in en üstüne pushlama
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

void print_stack(Stack *s) {
    if (s->top == NULL) {
        printf("Bos yapi\n");
        return;
    }

    Node *mevcut = s->top;

    while (mevcut != NULL) {
        printf("%d\n", mevcut->data);
        mevcut = mevcut->next;
    }
}

int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Bos yapi\n");
        return -1;
    }

    int icerik = s->top->data;

    Node *temp = s->top;

    s->top = s->top->next;
    
    free(temp);
    return icerik;
}


int main() {
    Stack s;
    s.top = NULL;

    int silinecek_eleman = 0;


    for(int i = 10;i<=100;i+=10) {
        push(&s,i);
    }

    print_stack(&s);

    printf("\nSondan 4 eleman silelim.\n\n");

    for(int i = 0;i<4;i++) {
        silinecek_eleman = pop(&s);
        printf("%d silindi\n",silinecek_eleman);
    }

    printf("\nListenin son hali:\n\n");

    print_stack(&s);



    
    return 0;
}
