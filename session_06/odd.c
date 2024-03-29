#include<stdio.h>
#include<stdlib.h>

void odd(int n);
int main(void)
{
    int n = 11;
    odd(n);
    return 0 ;

}

void odd(int n)
{
    if(n==0)
       return ;
    else{
    if(n%2 == 1)
      printf(" %d ",n) ;
    odd(n -1);
    }

}