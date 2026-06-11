#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    float width;
    float height;
    char* color;

};


int main()
{

    struct Rectangle kwadrat1[4] ={
        {10.6f,5.7f,"red"},
        {10.6f,5.7f,"red"},
        {10.6f,5.7f,"red"},
        {10.6f,5.7f,"red"}
    };

    printf("Hello world!\n");
    return 0;
}
