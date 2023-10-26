#include<stdio.h>
#include<stdlib.h>
#include"dynamic_array.h"

array_t *create_array(ssize_t N)
{
    array_t * p = NULL;
    p = (array_t *) malloc(N * sizeof(array_t));
    if(p==NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    return p;
}
status_t get(array_t *p_arr,index_t index,data_t * p_data){
    
    *p_data  = p_arr -> arr[index];
    return SUCCESS;
}
status_t set(array_t *p_arr,index_t index,data_t  new_data)
{

    p_arr -> arr[index] = new_data ;
    return SUCCESS;
}
status_t sort(array_t *p_arr){

}
index_t search(array_t *p_arr,data_t search_element);
void show(array_t *p_arr,const char *msg);
status_t destroy_array(array_t ** pp_array);
