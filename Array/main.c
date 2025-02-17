#include <stdio.h>
#include "array.h"

int main (){
    int nums[] = {0,1,2,2,3,0,4,2};
    int result = removeElement1(nums, 8, 2);
    printf("%d\n",result);
    for (int i = 0; i < 8; i++)
    {
       printf(" %d",nums[i]);
    }
    
    return 0;
}