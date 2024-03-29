#ifndef _BST_H
#define _BST_H

#define SUCCESS 1 
#define BST_dATA_NOT_FOUND 2 
#define BST_EMPTY    3
#define BST_NO_INRDER_SUCCESSOR  4
#define BST_NO_INORDER_PREDECESSOR 5

typedef int data_t ;
typedef int status_t;
typedef long long ssize_t;
typedef struct bst_node bst_node_t ;
typedef struct bst bst_t;

struct bst__node{
    data_t data ;
    struct bst_node * left ;
    struct bst_node *right ;
    struct bst_node *parent ;
} ;

struct bst {
   
   bst_node_t *root_node ;
   ssize_t number_of_element;
};


#endif  /*_BST_H*/