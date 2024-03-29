#ifndef _DCLL_H
#define _DCLL_H

#include<stdio.h>
#define SUCCESS 1
#define TRUE 1 
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int status_t;
typedef int data_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t dcll_t;

struct node{
    data_t data;
    node_t * prev;
    node_t * next;
};

dcll_t *create_list(void);
status_t insert_start(dcll_t *p_list, data_t new_data);
status_t insert_end(dcll_t *p_list,data_t new_data);
status_t insert_before(dcll_t *p_list,data_t e_data,data_t n_data);
status_t insert_after(dcll_t *p_list, data_t e_data,data_t n_data);

status_t remove_start(dcll_t *p_list);
status_t remove_end(dcll_t *p_list);
status_t remove_data(dcll_t *p_list,data_t e_data);

status_t get_start(dcll_t *p_list,data_t *p_start_data);
status_t get_end(dcll_t *p_plist, data_t *p_end_data);

status_t clear_list(dcll_t *p_list);

status_t is_list_empty(dcll_t *p_list);
status_t find(dcll_t *p_list,data_t f_data);
len_t get_list_lenght(dcll_t *p_list);

void show_list(dcll_t *p_list,const char *msg);
status_t destroy_list(dcll_t **pp_list);

static void generic_insert(node_t * beg,node_t * mid,node_t* end);
static void generic_delete(node_t *beg);
static node_t *search_node(dcll_t *p_list,data_t s_data);
static node_t *get_node(data_t new_data);
static void * xmalloc(size_t size_n_byte);

//interlist routine

dcll_t * get_concat_list(dcll_t * p_list_1,dcll_t *p_list_2);
status_t concat_list(dcll_t *p_list_1,dcll_t *p_list_2);
dcll_t *merge_list(dcll_t *p_list_1,dcll_t *p_list_2);

data_t *to_array(dcll_t *p_array,int *pn);
dcll_t *to_list(data_t *p_array,int n);
dcll_t *get_reverse_list(dcll_t *p_list);
status_t reverse_list(dcll_t *p_list);

#endif /*_DCLL_H*/
