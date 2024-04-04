#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "rb_tree.h"

rbtree_t *create_rbtree(void){
    
    rbtree_t *p_rbtree = (rbtree_t *) xcalloc(1,sizeof(rbtree_t));
    p_rbtree -> N = 0 ;
    p_rbtree -> nil = (rbnode_t *)xcalloc(1,sizeof(rbnode_t)); 
    p_rbtree-> nil-> data = -1 ;
    p_rbtree -> nil -> color = BLACK;
    p_rbtree -> nil -> left = NULL ;
    p_rbtree -> nil -> right = NULL ;
    p_rbtree -> nil  -> parent = NULL ;
    p_rbtree -> root_node = p_rbtree -> nil ;
    return(p_rbtree);

}

status_t insert_into_rbtree(rbtree_t *p_rbtree, data_t new_data)
{
    rbnode_t *p_run = NULL ;
    rbnode_t *z     = NULL ;

    z = get_rbnode(new_data,p_rbtree -> nil);
    
    if(p_rbtree -> root_node == p_rbtree -> nil)
    {
        p_rbtree -> root_node = z ;
        p_rbtree -> N +=1;

        rb_insert_fixup(p_rbtree,z);
        return(SUCCESS);
    }

    p_run = p_rbtree -> root_node;
    while(TRUE)
    {
        if(new_data <= p_run -> data)
        {
            if(p_run -> left == p_rbtree -> nil )
            {
                p_run -> left = z ;
                z -> parent = p_run;
                break;
            }
            else 
               p_run = p_run ->left;
        }

        else {
            if(p_run -> right == p_rbtree -> nil)
            {
                p_run -> right = z ;
                z -> parent = p_run;
                break;
            }
            else 
               p_run = p_run -> right;
        }
    }

    p_rbtree -> N += 1;
    rb_insert_fixup(p_rbtree,z);
    return SUCCESS;
}

rbnode_t *get_rbnode(data_t new_data,rbnode_t *nil){
    rbnode_t *p_new_rbnode = NULL ;

    p_new_rbnode = (rbnode_t *) xcalloc(1,sizeof(rbnode_t));
    p_new_rbnode -> data = new_data;
    p_new_rbnode -> color = RED;
    p_new_rbnode -> left = nil ;
    p_new_rbnode -> right = nil ;
    p_new_rbnode ->parent = nil;

    return(p_new_rbnode);
}
void *xcalloc(size_t nr_element,size_t size_per_element){
    void *p = NULL;
    p = calloc(nr_element,size_per_element);
    assert(p!=NULL) ;
    return(p);

}

void inorder_walk(rbtree_t *p_tree){
    puts("inorder walk");
    printf("[start] <->");
    inorder_node_walk(p_tree -> root_node,p_tree -> nil);
    puts("END");
}


void inorder_node_walk(rbnode_t *p_rbnode,rbnode_t *nil){
    if(p_rbnode != nil){
        inorder_node_walk(p_rbnode -> left, nil);
        printf("[%d] <->",p_rbnode -> data);
        inorder_node_walk(p_rbnode -> right,nil);
        
    }
}

void rb_insert_fixup(rbtree_t *p_rbtree,rbnode_t *z)
{
    
     rbnode_t *y = NULL ;
     while(z -> parent -> color == RED)
     {

        if(z -> parent  == z -> parent -> parent -> left)
        {
            y =  z -> parent -> parent -> right ;
            
                if(y -> color == RED)
                {
                    z -> parent -> color = BLACK ;
                    y -> color = BLACK;
                    z -> parent -> parent -> color = RED;
                    z = z -> parent -> parent;

                }

                else
                {
                   if(z == z -> parent ->right){
                    z = z -> parent ;
                    left_rotate(p_rbtree,z);
                   }
                   z -> parent -> color = BLACK ;
                   z -> parent -> parent-> color = RED;
                   right_rotate(p_rbtree,z -> parent -> parent);
                }
            
        }

        else
        {
            y = z -> parent -> parent -> left ;
            if(y -> color == RED)
            {
              z -> parent -> color = BLACK ;
              y -> color = BLACK;
              z -> parent -> parent -> color = RED ;
              z = z -> parent -> parent ;
            }
            else 
            {
                if(z == z -> parent -> left)
                {
                    z = z -> parent ;
                    right_rotate(p_rbtree,z);
                }

                z -> parent -> color = BLACK ;
                z -> parent -> parent -> color = RED;
                left_rotate(p_rbtree,z -> parent->parent);
            }
        } 
        
     }
     p_rbtree -> root_node -> color = BLACK;
}

void left_rotate(rbtree_t *p_tree,rbnode_t *x){
    
    rbnode_t *y = NULL ;
    
    y = x -> right;
    x-> right = y -> left ;
    if(y-> left != p_tree -> nil)
       y ->left -> parent = x ;

    y -> parent = x -> parent;
    if(x -> parent == p_tree-> nil)
       p_tree -> root_node = y ;
    else if(x == x -> parent -> left)
         x -> parent -> left = y;
    else if(x = x -> parent -> right)
        x -> parent -> right = y ;
    y -> left = x ;
    x -> parent = y ;
}

void right_rotate(rbtree_t *p_tree,rbnode_t *x)
{
    
   rbnode_t *y = NULL ;
   y =  x -> left;
   x -> left = y -> right ;
   if(y -> right != p_tree-> nil)
       y -> right -> parent = x ;
    
    y -> parent = x -> parent ;
    if(x ->parent == p_tree -> nil)
        p_tree -> root_node =  y ;
    else if(x == x -> parent -> left)
       x -> parent -> left = y ;
    else if(x == x -> parent -> right)
        x -> parent -> right = y ;

    x -> parent = y ;
    y -> right = x ; 
}

unsigned int  get_rb_height(rbtree_t *p_tree){
    puts("height");
    return get_height_nodelevel(p_tree,p_tree -> root_node );
}

unsigned int get_height_nodelevel(rbtree_t *p_tree,rbnode_t *p_node)
{
    
    if(p_node == NULL)
        return 0;
    return(cpa_max(get_height_nodelevel(p_tree,p_node -> left),
              get_height_nodelevel(p_tree,p_node -> right)) + 1);
}

int cpa_max(int a, int b){
    
    if(a > b)
        return a;
    else 
        return b ;
}