#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define search_failed -1 

int binary_search(int *a,int start_index,int end_index,int search_element);
void insertion_sort(int *arr,int N);

int main(int argc,char *argv[])
{
    int *a  = NULL ;
    int N = 0;
    int ret ;

    if(argc != 2)
    {
        printf("Usage error : %s number of elemts \n",argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if(N <= 0)
    {
        printf("bad array size \n");
        exit(EXIT_FAILURE);
    }

    a = (int * ) malloc(N * sizeof(int));
    if(a == NULL)
    {
        printf("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i< N;i++)
       a[i] = rand();
    
    insertion_sort(a,N);

    int know_data[] = {a[0],a[rand()%N],a[rand()%N],a[rand()%N],a[N - 1] };
    int not_known[] = {-400,-200,-900};
    
    for(i=0;i<5;i++)
    {
        ret = binary_search(a,0,N-1,know_data[i]);
        //assert(ret >=0);
        printf("data %d is found at index %d \n",know_data[i],ret);
    }

    for(i=0;i<3;i++)
    {
        ret = binary_search(a,0,N-1,not_known[i]);
        assert(ret == search_failed);
        printf("%d does not exist in array \n ",not_known[i]);
    }

   free(a);
   a = NULL ;
   return(EXIT_SUCCESS);
    }


int binary_search(int* a, int start_index, int end_index, int search_element){
    int mid;

    if(start_index <= end_index){
        mid = (start_index + end_index) / 2; 
        if(search_element == a[mid])
            return (mid); 
        else if(search_element < a[mid])
            return (binary_search(a, start_index, mid-1, search_element)); 
        else 
            return (binary_search(a, mid+1, end_index, search_element)); 
    }

    return (search_failed); 
}


void insertion_sort(int *arr,int N){
    int i,j;
    int key ;
    for(j = 1;j< N;j++)
       {
        key = arr[j];
        i = j - 1;

        while(i > - 1 && arr[i] > key)
           {
           arr[i + 1] = arr[i] ;
           i = i - 1 ;
           }
           arr[i + 1] = key ;

       }
}

