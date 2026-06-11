#include <stdio.h>
#include <stdlib.h>

void wStrCopyNew(wchar_t tab1[],wchar_t tab2[]){
    int i=0;
    while(tab1[i] != '\0'){
         tab2[i] = tab1[i];
        i++;
    }

}



int main()
{
    wchar_t tab1[] = L"dupapapapa";
    wchar_t tab2[60];
    wStrCopyNew(tab1,tab2);
    wprintf(L"%ls",tab2);
    return 0;
}
