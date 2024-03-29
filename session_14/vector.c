#include <stdio.h> 
#include <stdlib.h> 
#include "vector.h"

vector_t* create_array(ssize_t N){
    if(N <=0)
        return NULL;    
    vector_t * p_arr = NULL ;
    p_arr = (vector_t *) xcalloc(1,sizeof(vector_t));
    p_arr -> N = N;
    p_arr->arr = (data_t *)xcalloc(N,sizeof(data_t));
    
    return p_arr;
}

status_t get(vector_t* p_vec, index_t index, data_t* p_data){
    if(index < 0 || index >= p_vec->N)
        return INDEX_OUT_OF_RANGE;
    *p_data = p_vec->arr[index];
    return SUCCESS;
}

status_t set(vector_t* p_vec, index_t index, data_t new_val){
    if(index < 0 || index >= p_vec ->N)
        return INDEX_OUT_OF_RANGE;
    p_vec ->arr[index] = new_val;
    return SUCCESS;
}

status_t push_back(vector_t* p_vec, data_t new_val){
    
    p_vec->arr = (data_t *) realloc(p_vec->arr,(p_vec->N +1)*sizeof(data_t));
    if(p_vec -> arr == NULL)
    {
       puts("failed to allocate the memory");
       exit(EXIT_FAILURE);
    }
    p_vec -> N = p_vec -> N + 1;
    p_vec->arr[p_vec -> N] = new_val;
    return SUCCESS;
}

status_t pop_back(vector_t* p_vec, data_t* p_poped_val){
    *p_poped_val = p_vec ->arr[p_vec->N -1];
    p_vec->arr = (data_t *) realloc(p_vec->arr,(p_vec->N - 1)*sizeof(data_t));
    if(p_vec ->arr == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    p_vec-> N-=1;
    return SUCCESS;
}

status_t sort(vector_t* p_vec) // Use quick sort 
{
    quick_sort(p_vec->arr,0,p_vec-> N-1);
    return SUCCESS;
}

index_t search(vector_t* p_vec, data_t search_element){
   index_t i;
   for(i=0;i<p_vec->N;i++)
      if(p_vec->arr[i]==search_element)
         return i;
    return(-1);
}

ssize_t size(vector_t* p_vec)
{
    return p_vec -> N;
}

void show(vector_t* p_vec, const char* msg){
    if(msg)
       puts(msg);
    index_t i;
    for(i=0;i<p_vec->N;i++)
       printf("p_vec->arr[%lld]:%d\n", i, p_vec->arr[i]); 
}

status_t destroy_array(vector_t** pp_vecay){
    vector_t *p_vec =  NULL;
    p_vec = *pp_vecay;
    free(p_vec -> arr);
    free(p_vec);
    pp_vecay = NULL;
    return(SUCCESS);
}

/* Array Auxillary Functions */
static void quick_sort(data_t* arr, index_t p, index_t r){
    index_t q;
    if(p<r)
    {
        q = partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}

static index_t partition(data_t* arr, index_t p, index_t r){
    
    index_t i,j;
    data_t pivot,temp;
    pivot = arr[r];
    i = p -1 ;
    for(j=p;j<r;j++)
    {
        if(arr[j] <=pivot)
        {
            i = i + 1;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    
    i = i +  1;
    temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return i;

}

/* General Purpose Auxillary Functions */
static void* xcalloc(size_t nr_elements, size_t size_per_element){
    
    void *p = NULL;
    p = calloc(nr_elements,size_per_element);
    if(p==NULL)
    {
        puts("failed to allocate the mem");
        exit(EXIT_FAILURE);
    }
    return(p);

}