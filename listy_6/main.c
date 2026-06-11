#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};


struct element* addLast(struct element* lista,int a){
    struct element* el1 = (struct element*)malloc(sizeof(struct element));

    el1->x=a;
    el1->next =NULL;
    if(lista==NULL){
        return el1;
    }

    struct element*obecny = lista;
    while(obecny->next != NULL){
        obecny=obecny->next;
    }
    obecny->next = el1;

    return lista;
};
int main()
{
    struct element* mojalista = NULL;
    mojalista = addLast(mojalista,6);
    mojalista = addLast(mojalista,7);
    mojalista = addLast(mojalista,7);
    printf("%d",mojalista->x);
    printf("%d",mojalista->next->x);
    printf("%d",mojalista->next->x);



    return 0;
}
