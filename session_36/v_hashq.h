#ifndef _V_HASHQ_H
#define _V_HASHQ_H

#include "common.h"

struct vhashq{
    vlist_t **ppv_head_node ;
    ssize_t bucket_size;
};

vhashq_t *v_create_hashq(ssize_t bucket_size);
status_t v_add_hashq(vhashq_t *pv_hashq,vertex_t v);
status_t v_remove_hashq(vhashq_t *pv_hashq,vertex_t v);
vnode_t *v_search_hashq(vhashq_t *pv_hashq,vertex_t v);
status_t v_destroy_hashq(vhashq_t **ppv_hashq); 

#endif