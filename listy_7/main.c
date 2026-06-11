#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};

struct element* addFirst(struct element* glowa,int a){
    struct element* el1 = (struct element*)malloc(sizeof(struct element));

    el1 ->x=a;
    el1->next = glowa->next;
    glowa->next=el1;



};

int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    glowa -> next =NULL;

    addFirst(glowa,5);
    printf("%d",glowa->next->x);

    return 0;
}
