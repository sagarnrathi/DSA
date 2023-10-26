#ifndef _ARRAY_H
#define _ARRAY_H

#define SUCCESS 1
#define INDEX_OUT_OF_RANGE 2

typedef struct array array_t;
typedef int data_t;
typedef int status_t;
typedef long long ssize_t;
typedef ssize_t index_t;

struct array{
    data_t *array;
    ssize_t N;
};

//array interface function
array_t * create_array(ssize_t N);
status_t get(array_t * p_array,index_t N,data_t *p_data );
status_t set(array_t *p_array,index_t N,data_t new_element);
status_t sort(array_t * p_array);
index_t search(array_t * p_array,data_t element);
ssize_t size(array_t *p_array);
void show(array_t *p_array,const char *msg);
status_t destroy_array(array_t **pp_array);

//array auxillary function 
static void quick_sort(data_t *p_arr,index_t p,index_t r);
static index_t partition(data_t * p_array,index_t p,index_t r );

//general purpse auxilary function 

static void *xcalloc(ssize_t nr_element,ssize_t size);

#endif // _ARRAY_H