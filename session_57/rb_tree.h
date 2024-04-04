#ifndef _RB_TREE
#define _RB_TREE
#endif
#include<stdio.h>

#define SUCCESS 1 
#define DATA_NOT_FOUND  2
#define TRUE 1
#define FALSE 0

typedef struct rb_node rbnode_t ;
typedef struct rb_tree rbtree_t ;
typedef enum color color_t ;
typedef int data_t;
typedef int status_t;

enum color {
    RED = 0 ,
    BLACK
} ;

struct rb_node{
    data_t data;
    color_t color;
    struct rb_node *left;
    struct rb_node *right;
    struct rb_node *parent;
};

struct rb_tree{
    rbnode_t *root_node;
    rbnode_t *nil ;
    int N ;
};


rbtree_t *create_rbtree(void);
status_t insert_into_rbtree(rbtree_t* p_rbtree,data_t new_data);
status_t remove_from_rbtree(rbtree_t *P_rbtree,data_t r_data);
status_t destroy_rbtree(rbtree_t **pp_rbtree);
status_t find_rb_data(rbtree_t p_rbtree,data_t search_data);
unsigned int  get_rb_height(rbtree_t *p_tree);

void preorder_walk(rbtree_t *p_rbtree);
void postorder_walk(rbtree_t *p_rbtree);
void inorder_walk(rbtree_t *p_rbtree);

status_t get_rb_max(rbtree_t *p_tree,data_t *p_data_max);
status_t get_rb_min(rbtree_t *p_tree,data_t *P_data_min);

status_t get_rb_inorder_successor(rbtree_t *p_rbtree, data_t e_data ,
                                 data_t *p_succ_data
                                 );
status_t get_rb_inorder_predecessor(rbtree_t *p_rbtree,data_t e_data ,
                                   data_t *p_pred_data
                                   );

rbnode_t *search_rb_node(rbtree_t *p_tree,data_t search_data);

void rb_insert_fixup(rbtree_t *p_rbtree,rbnode_t *z);
void rb_delete_fixup(rbtree_t *p_rbtree,rbnode_t *z);
void rb_tranplant(rbtree_t *p_rbtree,rbnode_t *u,rbnode_t *v);

void left_rotate(rbtree_t *p_tree,rbnode_t *x);
void right_rotate(rbtree_t *p_tree, rbnode_t *x);

unsigned int get_height_nodelevel(rbtree_t *p_tree,rbnode_t *p_node);
void preorder_node_walk(rbnode_t *p_rbnode,rbnode_t *nil);
void postorder_node_walk(rbnode_t *p_rbnode,rbnode_t *nil);
void inorder_node_walk(rbnode_t *p_rbnode,rbnode_t *nil);


void destroy_node_level(rbnode_t *p_root_node,rbnode_t *nil);

rbnode_t *get_rb_max_node(rbtree_t *p_tree,rbnode_t *p_rbnode);
rbnode_t *get_rbnode(data_t new_data,rbnode_t *nil);
void *xcalloc(size_t nr_element,size_t size_per_element);