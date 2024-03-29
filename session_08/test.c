#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TRUE 1

void merge_proc(int *a,int p,int q ,int r);
void merge_sort(int *a,int start,int end);
void show_sub_array(int *a,int start_index,int end_index,const char *msg);

int main(void)
{
    int a[] = {
        75,32,14,90,
        10,20,30,40,50,
        15,25,35,45,55,65,75,
        -10,24,67,18
    };

    int p = 0,r = 19;

    show_sub_array(a,p,r,"before merge proc");
    merge_sort(a,p,r);
    show_sub_array(a,p,r,"after merge ");

    return(EXIT_SUCCESS);

}

void merge_proc(int *a,int p,int q,int r)
{
    int *a1 = NULL ;
    int *a2 = NULL ;
    int N1 = q - p + 1;
    int N2 = r - q ;
    int i = 0,j = 0,k = 0 ;

    a1 = (int *) malloc(N1 * sizeof(int));
    if(a1 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    a2 = (int *) malloc(N2 * sizeof(int));
    if(a2 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);

    }

    for(i = 0;i<N1;i++)
       a1[i] = a[p + i];
    
    for(i = 0 ; i< N2 ; i++)
       a2[i] = a[1 + q + i];
    i = 0;

    while(TRUE)
    {
     if(a1[i] <= a2[j])
     {
        a[p + k ] = a1[i];
        i = i + 1 ;
        k = k + 1 ;
        if(i ==N1)
        {
             while(j < N2){
            a[p + k] = a2[j];
            k = k + 1 ;
            j = j + 1;
            }
            break ;
        }
     }
     else {
        a[p + k ] = a2[j];
        j = j + 1;
        k = k + 1 ;
        if(j == N2)
        {
            while(i < N1)
            {
            a[p + k] = a1[i];
            k = k+1 ;
            i = i + 1 ;
            }
            break;

        }

     }

    }
free(a1) ;
free(a2);
a1 = NULL;
a2 = NULL ;
}


void show_sub_array(int *a,int start_index,int end_index,const char *msg)
{
    puts("-------------");
    int i = 0;
    if(msg)
        puts(msg);
    for(i = start_index ;i <= end_index;i++)
    {
        printf("a[%d] : %d \n",i,a[i]);
    }
}

void merge_sort(int *a,int start,int end){
    int mid = ( start + end ) / 2 ;
    if(start < end)
    {
        merge_sort(a,start,mid);
        merge_sort(a,mid +1 , end);
        merge_proc(a,start,mid,end);
    }
}