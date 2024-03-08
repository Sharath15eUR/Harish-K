#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int n=0;
    while(num!=0){
        if(num%2==1)
        n++;
        num=num/2;
    };
    printf("Count of bits: %d", n);
    return 0;
}
