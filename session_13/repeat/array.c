#include<stdio.h>
#include<stdlib.h>
#include"array.h"

array_t * create_array(ssize_t N){
    array_t * p_array = NULL;
    
    if(N <=0)
       return NULL;

    p_array = (array_t *) xcalloc(1,sizeof(array_t));
    p_array-> N = N ;
    p_array -> array = (int *) xcalloc(N,sizeof(data_t));
    return (p_array);    
}

status_t get(array_t * p_array,index_t index,data_t *p_data ){
    
     if(index < 0 || p_array -> N <= index)
         return INDEX_OUT_OF_RANGE ;
    *p_data = p_array->array[index];
    return SUCCESS ;
}

status_t set(array_t *p_array,index_t index,data_t new_element){
    if(index < 0 || index >= p_array-> N)
       return INDEX_OUT_OF_RANGE;
    p_array -> array[index] = new_element;
    return SUCCESS; 
}

status_t sort(array_t * p_array){
    quick_sort(p_array->array,0,p_array->N -1 );
    return SUCCESS;
}

index_t search(array_t * p_array,data_t element){
    index_t i;
    for(i=0;i< p_array->N;i++)
        if(p_array->array[i]== element)
        return i;
    return -1;
}
ssize_t size(array_t *p_array){
    return p_array->N;
}
void show(array_t *p_array,const char *msg){
    index_t i;
    if(msg)
       puts(msg);
    
    for(i=0;i<p_array->N;i++)
        printf("p_array ->array[%lld] : %d \n",i,p_array->array[i]);
}
status_t destroy_array(array_t **pp_array){
    
    array_t *p_array = NULL ;
    p_array = *pp_array;
    free(p_array->array);
    free(p_array);
    *pp_array = NULL ;

    return(SUCCESS);
}

//array auxillary function 
static void quick_sort(data_t *p_array,index_t p,index_t r){
    index_t q ;
    if(p<r){
    q = partition(p_array,p,r);
    quick_sort(p_array,p,q-1);
    quick_sort(p_array,q+1,r);
    }
}
static index_t partition(data_t * p_array,index_t p,index_t r ){
    data_t pivot,temp;
    index_t i,j;
    pivot = p_array[r];
    i = p - 1;
    for(j = p;j<r;j++ )
    {
        if(p_array[j]<= pivot)
        {
            i = i + 1 ;
            temp = p_array[i] ;
            p_array[i] = p_array[j];
            p_array[j] = temp;
        }
    }
        i = i + 1;
        temp = p_array[r];
        p_array[r] = p_array[i];
        p_array[i] = temp;
        return i;

}
//general purpse auxilary function 

static void *xcalloc(ssize_t nr_element,ssize_t size){
    void *p = NULL;
    p = calloc(nr_element,size);
    if(p == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    return(p);
}