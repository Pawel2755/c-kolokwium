#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node * next;
};

struct node* rotateRight(struct node* lista,unsigned int k){
    struct node* oldTail = lista;
    int length = 1;

    while(oldTail->next!=NULL){
        oldTail=oldTail->next;
        length++;
    }
    k = k%length;
    if(k==0){
        return lista;
    }
    oldTail->next=lista;

    struct node* newTail = lista;
    for(int i=0;i<length-k-1;i++){
        newTail=newTail->next;
    }
    struct node* newHead = newTail->next;
    newTail->next=NULL;
    return newHead;
}



void printlist(struct node* lista){
    struct node* obecny = lista;
    while(obecny!=NULL){
        printf("%d",obecny->value);
        obecny=obecny->next;

    }

}


int main()
{
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));
    struct node* el4 = (struct node*)malloc(sizeof(struct node));
    struct node* el5 = (struct node*)malloc(sizeof(struct node));
    struct node* el6 = (struct node*)malloc(sizeof(struct node));

    el1->value=1;
    el1->next=el2;
    el2->value=2;
    el2->next=el3;
    el3->value=2;
    el3->next=el4;
    el4->value=4;
    el4->next=el5;
    el5->value=5;
    el5->next=el6;
    el6->value=6;
    el6->next=NULL;

    struct node* lista = el1;
    printlist(rotateRight(lista,1));


    return 0;
}
