#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int countNodes(struct element* glowa){
    int i=0;
    struct element* obecny = glowa->next;
    while(obecny != NULL){
        i++;
        obecny= obecny ->next;
    }
    return i;

};

int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    struct element * el1 = (struct element*)malloc(sizeof(struct element));
    struct element * el2 = (struct element*)malloc(sizeof(struct element));
    struct element * el3 = (struct element*)malloc(sizeof(struct element));

    glowa->next=el1;

    el1->x=10;
    el1->next = el2;
    el2->x=20;
    el2->next = el3;
    el3->x=30;
    el3->next = NULL;

    printf("%d\n",countNodes(glowa));
    return 0;
}
