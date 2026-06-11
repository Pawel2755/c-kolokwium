#include <stdio.h>
#include <stdlib.h>


struct element {
    int x;
    struct element * next;
};

void addFirst(struct element* glowa,int a){
    struct element* obecny = (struct element*)malloc(sizeof(struct element));
    obecny->x=a;
    obecny->next=glowa->next;
    glowa->next=obecny;
};

void printList(struct element* glowa){
    struct element* obecny = glowa->next;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }

}

int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));
    glowa->next=el1;


    el1->x=10;
    el1->next=el2;
    el2->x=20;
    el2->next=el3;
    el3->x=30;
    el3->next=NULL;

    addFirst(glowa,5);
    printList(glowa);





    return 0;
}
