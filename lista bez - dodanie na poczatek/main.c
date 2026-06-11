#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

void napoczatek(struct element** lista,int n){
    struct element* nowy = (struct element*)malloc(sizeof(struct element));
    nowy->x=n;
    nowy->next = *lista;
    *lista=nowy;



}
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

    el1->x=1;
    el1->next=el2;
    el2->x=3;
    el2->next=el3;
    el3->x=7;
    el3->next=NULL;

    struct element* lista = el1;
    napoczatek(&lista,5);

    printlist(lista);

    return 0;
}
