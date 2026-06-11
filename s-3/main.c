#include <stdio.h>
#include <stdlib.h>

struct node {
    int i;
    struct node * next;
};

void duplicateLastWithoutHead(struct node* lista){
    struct node* obecny =lista;
    while(obecny->next!=NULL){
        obecny=obecny->next;
    }
    struct node* nowy = (struct node*)malloc(sizeof(struct node));
    nowy->i=obecny->i;
    nowy->next=NULL;
    obecny->next=nowy;
}

void printlist(struct node* lista){
 struct node* obecny = lista;

    while(obecny!=NULL){
        printf("%d\n",obecny->i);
        obecny=obecny->next;
    }


}


int main()
{
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));

    el1->i=411;
    el1->next=el2;
    el2->i=51;
    el2->next=el3;
    el3->i=25;
    el3->next=NULL;

    struct node* lista=el1;
    duplicateLastWithoutHead(lista);
    printlist(lista);
    return 0;
}
