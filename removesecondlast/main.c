#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

void removesecondlast(struct element* lista){
    struct element* obecny = lista;
    while(obecny->next->next->next!=NULL){
        obecny=obecny->next;
    }
    struct element* dousun = obecny->next;
    free(dousun);
    obecny->next=obecny->next->next;


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
    removesecondlast(lista);
    printlist(lista);


    return 0;
}
