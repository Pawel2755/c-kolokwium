#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node * next;
};

struct node* segregateEvenOdd(struct node* lista){
    struct node* oddStart=NULL;
    struct node* oddEnd = NULL;
    struct node* evenStart = NULL;
    struct node* evenEnd = NULL;
    struct node* obecny = lista;
    while(obecny!=NULL){
        int i = obecny->value;
        if(i%2==0){
            if(evenStart==NULL){
                evenStart=obecny;
                evenEnd = evenStart;
            }else{
                evenEnd->next=obecny;
                evenEnd=evenEnd->next;
            }
        }
        else{
            if(oddStart==NULL){
                oddStart=obecny;
                oddEnd=oddStart;
            }
            else{
                oddEnd->next=obecny;
                oddEnd=oddEnd->next;
            }
        }
        obecny=obecny->next;
    }
    if(evenStart==NULL){
        return oddStart;
    }
    if(oddStart==NULL){
        return evenStart;
    }
    evenEnd->next=oddStart;
    oddEnd->next=NULL;
    return evenStart;



};



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

    printlist(segregateEvenOdd(lista));

    return 0;
}
