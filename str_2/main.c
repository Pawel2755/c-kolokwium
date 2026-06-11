#include <stdio.h>
#include <stdlib.h>

enum Month{
    sty=1,
    lut,
    marz,
    kwie,
    maj,
    czer,
    lip,
    sier,
    wrze,
    paz,
    list,
    gru

};
int days_in_month(enum Month m){
    switch(m){
case sty:
case marz:
case maj:
case lip:
case sier:
case paz:
case gru:
    return 31;
case kwie:
case czer:
case wrze:
case list:
    return 30;
case lut:
    return 28;
    }

}



int main()
{
    enum Month test1 = sty;
    enum Month test2 = lut;
    enum Month test3 = kwie;
    printf("%d\n",days_in_month(test1));
    printf("%d\n",days_in_month(test2));
    printf("%d\n",days_in_month(test3));
    return 0;
}
