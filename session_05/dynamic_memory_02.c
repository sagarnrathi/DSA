#include<stdio.h>
#include<stdlib.h>

int* get_array_1(int * pN);

int main(void)
{
    int *a = NULL ;
    int N  = 8 ;
    int i;

    int *a1 = NULL ;
    int N1 ;
    a = (int *) malloc(N * sizeof(int));
    if(a == NULL)
    {
        printf("failed to allocate the memory ");
       exit(EXIT_FAILURE) ;
    }
    
    for(i = 0;i < N ;++i)
       a[i] = (i +1) * 10 ;
    
    for(i = 0; i < N ;i++)
       printf("a[%d] : %d ",i,a[i]);
    
    free(a);
    a = NULL;
   exit(EXIT_SUCCESS);

   puts("get and release a1 ");

   a1 = get_array_1(&N1);
   for(i = 0;i<N1;i++)
      printf("a[%d] : %d",i,a[i]);
    free(a1);
    a1 = NULL ;
    exit(EXIT_SUCCESS);

}

int* get_array_1(int *pN)
{
    int *a = NULL ;
    int N = 8 ;
    int i ;
    
}