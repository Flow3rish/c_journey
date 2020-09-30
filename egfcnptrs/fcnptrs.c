#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main(int argc, char const *argv[])
{
    int (*secti)(int, int) = add;
    int a = secti(3, 4);
    printf("test: %d", a);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}