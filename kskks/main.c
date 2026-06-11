#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

struct element* wstaw(struct element* lista, int a){
    struct element* obecny = lista;
    struct element* nowy = (struct element*)malloc(sizeof(struct element));
    if(lista == NULL || lista->x >=a){
        nowy->x=a;
        nowy->next=lista;
        return nowy;
    }
    while(obecny!=NULL && obecny->next->x < a){
        obecny=obecny->next;
    }
    nowy->x=a;
    nowy->next=obecny->next;
    obecny->next=nowy;
    return lista;
};




void printlist(struct element* lista){
    struct element* obecny = lista;
    while(obecny!=NULL){
        printf("%d",obecny->x);
        obecny=obecny->next;

    }

}


int main()
{
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    el1->x=2;
    el1->next=el2;
    el2->x=3;
    el2->next=el3;
    el3->x=7;
    el3->next=NULL;

    struct element* lista = el1;
    struct element* wstaws = wstaw(lista,5);
    printlist(wstaws);

    return 0;
}
