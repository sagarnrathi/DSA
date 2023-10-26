#ifndef _ARRAY_H
#define _ARRAY_H

#define SUCCESS 1
#define TRUE 1 
#define INDEX_OUT_OF_RANGE 2

typedef struct array array_t;
typedef int data_t;
typedef int status_t;
typedef long long ssize_t;
typedef ssize_t index_t;

struct array{
    data_t* arr;
    ssize_t N;
};

array_t *create_array(ssize_t N);
status_t get(array_t *p_arr,index_t index,data_t * p_data);
status_t set(array_t *p_arr,index_t index,data_t * p_data);
status_t sort(array_t *p_arr);
index_t search(array_t *p_arr,data_t search_element);
void show(array_t *p_arr,const char *msg);
status_t destroy_array(array_t ** pp_array);
#endif