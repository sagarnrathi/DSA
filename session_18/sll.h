#ifndef _SLL_H
#define _SLL_H

#define SUCCESS 1
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3

typedef int data_t;
typedef int status_t;
typedef struct node node_t;
typedef node_t sll_t;

struct node{
    data_t data;
    struct node *next;
};


sll_t *create_list(void);
status_t insert_start(sll_t *p_list,data_t new_data);
status_t insert_end(sll_t *p_list,data_t new_data);
status_t insert_after(sll_t *p_list,data_t e_data,data_t new_data);
status_t insert_before(sll_t *p_list,data_t e_data,data_t new_data);

status_t remove_start(sll_t *p_list);
status_t remove_end(sll_t *p_list);
status_t remove_data(sll_t *p_list,data_t data);

void show_list(sll_t *p_list,const char*msg);

static node_t *get_node(data_t new_data);
static void * xmalloc(size_t size_in_bytes);

#endif  /*_SLL_H*/