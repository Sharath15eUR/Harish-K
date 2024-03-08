#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p1 = malloc(sizeof(int));
    int *p2 = malloc(sizeof(int));
    scanf("%d %d", p1, p2);
    *p1 = *p1+*p2;
    *p2 = *p1-*p2;
    *p1 = *p1-*p2;
    printf("%d %d", *p1, *p2);
}
