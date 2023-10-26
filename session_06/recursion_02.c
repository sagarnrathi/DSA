#include<stdio.h>
#include<stdlib.h>

void f(int n);
void g(int n);

int main(void)
{
    f(0);
    g(10);
    return(0);

}

void f(int n){
    if(n >=10)
        return ;
    
    f(n+1);
    printf("f() : n = %d \n",n);
}

void g(int n)
{
    if(n < 0)
         return ;
    printf("g () : n = %d\n ",n);
    g(n-1);
}