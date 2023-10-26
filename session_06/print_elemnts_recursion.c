#include<stdio.h>
#include<stdlib.h>

void print(int *a,int n);

int main(void)
{
    int a[] = {10,20,30,40,50,60,70,80,90,100};
    print(a,9);
    return 0 ;
}
void print(int *a,int n)
{
    if(n < 0)
       return ;
  
    print(a,n-1);
      printf("value is %d \n",*(a + n));
}