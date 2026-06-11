#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};

void printListWithoutHead(struct element* list){
    if(list == NULL){
        printf("Lista jest pusta");
    }
    struct element* obecny = list;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny = obecny -> next;
    }


}

int main()
{
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    el1->x =0;
    el1->next = el2;
    el2->x =0;
    el2->next = el3;
    el3->x =0;
    el3->next = NULL;

    struct element* list = el1;


    printListWithoutHead(list);
    return 0;
}
