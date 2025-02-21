#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int main (){
    char s[] = {"ADOBECODEBANC"};
    char t[] = {"ABC"};
    printf("%s",minWindow(s, t));
    return 0;
}