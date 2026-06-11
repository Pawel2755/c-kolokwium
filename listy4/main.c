#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};


struct element* removeSecondLastWithoutHead(struct element* lista){
    struct element* obecny = lista;
    while(obecny->next->next->next!=NULL){
        obecny=obecny->next;
    }
    struct element* przedostatni = obecny->next;
    obecny->next = przedostatni->next;
    return lista;

};


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

    struct element* lista = el1;
    struct element* obecny = lista;

    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }
    removeSecondLastWithoutHead(lista);
    obecny=lista;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }


    return 0;
}
