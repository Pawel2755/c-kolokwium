#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int i;
    struct node * next;
};

void printPerfectSquares(struct node* lista){
    struct node* obecny=lista;
    while(obecny!=NULL){
        int pods = (int)sqrt(obecny->i);
        if(pods*pods == obecny->i){
            printf("%d\n",obecny->i);
        }
        obecny=obecny->next;
    }



}



int main()
{
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));

    el1->i=4;
    el1->next=el2;
    el2->i=5;
    el2->next=el3;
    el3->i=25;
    el3->next=NULL;

    struct node* lista=el1;


    printPerfectSquares(lista);




    return 0;
}
