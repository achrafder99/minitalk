#include <stdio.h>

int main()
{
    unsigned int a;
    int j = 8;

    while(j > 0){
    a <<= j;
    printf("%d\n",a);
    j--;
}

    printf("%d\n",a<<4);

    return 0;
}
