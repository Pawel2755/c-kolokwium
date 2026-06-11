#include <stdio.h>
#include <stdlib.h>


struct element {
    int x;
    struct element * next;
};

struct element* addFirst(struct element* lista,int a){
    struct element* obecny = (struct element*)malloc(sizeof(struct element));
    obecny->x=a;
    obecny->next=lista;
    return obecny;
};

void printList(struct element* lista){
    struct element* obecny = lista;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }

}

int main()
{
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    el1->x=10;
    el1->next=el2;
    el2->x=20;
    el2->next=el3;
    el3->x=30;
    el3->next=NULL;
    struct element* lista=el1;

    printList(addFirst(lista,5));




    return 0;
}
