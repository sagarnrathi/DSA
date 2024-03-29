#ifndef _VLIST_H
#define _VLIST_H

#include"common.h"

struct vnode{
    vertex_t v;
    hhashq_t *p_adj_hashq;
    color_t color;

    struct vnode * next;
    struct vnode *prev;

} ;

vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 
status_t v_remove_vertex(vlist_t* pv_list, vertex_t v); 
status_t v_destroy_list(vlist_t* pv_list); 

void v_generic_insert(vnode_t* p_beg, vnode_t* p_mid, vnode_t* p_end); 
void v_generic_delete(vnode_t* p_delete_node); 
vnode_t* v_search(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_node(vertex_t v); 

#endif