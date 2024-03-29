#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void merge_proc(int *a,int p,int q,int r);
void show_sub_array(int *a,int start_index,int end_index ,const char * msg);

int main(void)
{
    int a[] = {
        75,32,14,90,
        10,20,30,40,50,
        15,25,35,45,55,65,75,
        -10,24,67,18
    };

    int p = 4 , q = 8, r = 15 ;
    show_sub_array(a,p,r,"before merge");
    merge_proc(a,p,q,r);
    show_sub_array(a,p,r,"after merge sort ");
}

void show_sub_array(int *a,int start_index,int end_index ,const char * msg)
{
    int i ;
    if(msg)
        puts(msg);
    for(i=start_index;i<end_index;i++)
    {
        printf("a[%d] : %d \n",i,a[i]);
    }
}

void merge_proc(int *a,int p,int q,int r)
{
    int *a1  = NULL ;
    int *a2  = NULL ;
    int n1 = q - p + 1 ;
    int n2  = r - q ;
    int i , j ,k ;
    
    a1 = (int *) malloc(n1 * sizeof(int));
    if(a1 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    a2 = (int * ) malloc(n2 * sizeof(int));
    
    if(a2 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    for(i = 0;i<n1;i++)
       a1[i] = a[p + i];

    for(i = 0; i < n2;i++)
       a2[i] = a[q + 1 + i];

}