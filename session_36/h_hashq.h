#ifndef _H_HASHQ 
#define _H_HASHQ

#include "hlist.h"
struct hhashq{
    hlist_t **pp_head_node;
    ssize_t bucket_size;
};

hhashq_t * h_create_hashq(ssize_t bucket_size);
status_t h_add_hashq(hhashq_t *p_hashq,vertex_t v,vnode_t *pv,double w );
status_t h_remove_hashq(hhashq_t *p_hashq,vertex_t vertex);
hnode_t *h_search_hashq(hhashq_t *p_hashq,vertex_t v);
status_t h_destroy_hashq(hhashq_t **pp_hashq);

#endif ;
