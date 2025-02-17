#include <stdio.h>
#include "Array.h"

int main (){
    int nums[] = {-1,0,3,5,9,12};
    int result = search(nums, 6, 9);
    printf("%d",result);
    return 0;
}