#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a&1) printf("The number is odd");
    else    printf("The number is even");
    return 0;
}
