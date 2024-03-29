#include<stdio.h>
#include<stdlib.h>

void f(void);

int main(void)
{
    f();
    return(0);
}

void f()
{
    puts("in f");
    f();
}