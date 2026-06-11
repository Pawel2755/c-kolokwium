#include <stdio.h>
#include <stdlib.h>

`




int main()
{
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    el1 ->x = 1;
    el1->next = el2;
    el2 ->x = 2;
    el2->next = el3;
    el3 ->x = 3;
    el3->next = NULL;

    struct element* lista = el1;
    struct element* obecny =lista;
    while(obecny!=NULL){
        printf("%d",obecny->x);
        obecny =obecny->next;
    }



    return 0;
}
