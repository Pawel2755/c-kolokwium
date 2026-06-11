#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node * next;
};
int hasCycle(struct node* lista){
    struct node* slow = lista;
    struct node* fast = lista;
    struct node* obecny = lista;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;


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
    printf("%d",hasCycle(lista));


    return 0;
}
