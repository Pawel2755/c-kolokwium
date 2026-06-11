#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int findMin(struct element* lista){
    int i= lista->x;
    while(lista->next!=NULL){
        if(i > lista->next->x){
            i= lista->next->x;
        }
        lista=lista->next;
    }
    return i;


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

    el1->x=2;
    el1->next=el2;
    el2->x=3;
    el2->next=el3;
    el3->x=1;
    el3->next=NULL;

    struct element* lista = el1;
    printf("%d",findMin(lista));

    return 0;
}
