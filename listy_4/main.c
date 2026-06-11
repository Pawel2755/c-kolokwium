#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};

void printListWithHead(struct element* glowa){
    if(glowa == NULL){
        printf("Lista jest pusta");
    }
    struct element* obecny = glowa->next;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny = obecny -> next;
    }


}

int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    glowa -> next =el1;

    el1->x =0;
    el1->next = el2;
    el2->x =0;
    el2->next = el3;
    el3->x =0;
    el3->next = NULL;




    printListWithHead(glowa);
    return 0;
}
