#include <stdio.h>

#include "escapeChars.h"

int main(){
    printf("%s", ESC "?1049h");
    printf("%sbb\n", MV0 );
    getchar();
    printf("%s", ESC "?1049l");
    return 0;
}

