#ifndef _AVL_H
#define _AVL_H

#define SUCCESS 1
#define AVL_DATA_NOT_FOUND 2
#define AVL_TREE_EMPTY  3

typedef struct avl_node avl_node_t;
typedef struct avl_tree avl_tree_t;
typedef int status_t;
typedef int data_t;
typedef int bool ;

struct avl_node {
    data_t data;
    struct avl_node *left;
    struct avl_node *right;
    struct avl_node *parent;
};

struct avl_tree{
    avl_node_t *p_root_node;
    unsigned long nr_elements;
};

avl_tree_t *create_avl_tree(void);
status_t insert_into_avl_tree(avl_tree_t *p_avl_tree,data_t new_data);
status_t remove_data_from_avl_tree(avl_tree_t *p_avl_tree,data_t r_data);
bool find_data_in_avl_tree(avl_tree_t *p_avl_tree,data_t f_data);
void inorder_walk(avl_tree_t *p_avl_tree);
unsigned long get_height_of_avl_tree(avl_tree_t *p_tree);
status_t get_avl_max(avl_tree_t *p_avl_tree,data_t *p_max_data);
status_t get_avl_min(avl_tree_t *p_avl_tree,data_t *p_min_data);
status_t destroy_avl_tree(avl_tree_t **pp_avl_tree);

avl_node_t *find_next_imbalanced_node(avl_node_t *p_avl_node);
long int get_balance_of_avl_node(avl_node_t *p_avl_node);
void left_rotate(avl_tree_t *p_tree,avl_node_t *p_avl_node);
void right_rotate(avl_tree_t *p_tree,avl_node_t *p_avl_node);
avl_node_t *search_avl_tree_nodelevel(avl_tree_t *p_avl_tree,data_t search_data);
void transplant(avl_tree_t *p_avl_tree,avl_node_t *u,avl_node_t *v);
unsigned long get_height_node_level(avl_node_t *p_avl_node);
void inorder_walk_nodelevel(avl_node_t *p_avl_node);
avl_node_t *get_avl_min_node(avl_node_t *p_avl_node);
avl_node_t *get_avl_max_node(avl_node_t *p_avl_node);
avl_node_t *get_avl_node(data_t new_data);
void *xcalloc(size_t nr_element,size_t size_per_element);
void destroy_nodelevel(avl_node_t *z);
unsigned long cpa_max(unsigned long a,unsigned long b);

#endif