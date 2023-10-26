#include<stdio.h>
#include<stdlib.h>

int fab(int n);

int main()
{
    int n = 7;
    int i = 0;
    for(i;i<n;i++)
        printf( " %d ",fab(i));
    fab(4);
    return 0;
}

int fab(int n)
{
    if(n==0)
       return 0;
    else if (n == 1)
        return 1;
    else 
    return fab(n-1) + fab(n-2 );
}