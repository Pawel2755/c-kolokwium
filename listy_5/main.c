#include <stdio.h>
#include <stdlib.h>


struct element {
    int x;
    struct element * next;
};

struct element* addFirst (struct element* lista,int a){

    struct element* el1 = (struct element*)malloc(sizeof(struct element));

    el1 ->x=a;
    el1 -> next = lista;


    return el1;


}



int main()
{
    struct element* mojalista = NULL;


    mojalista=addFirst(mojalista,5);
    printf("%d",mojalista->x);

    return 0;
}
