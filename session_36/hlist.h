#ifndef _HLIST_H
#define _HLIST_H

#include"common.h"

struct vnode ;
struct hnode {
    vertex_t v;
    vnode_t *pv;
    double w ;

    struct hnode *prev;
    struct hnode *next;
};

hlist_t *h_create_list(void);
status_t h_insert_end(hlist_t *ph_list,vertex_t v,vnode_t *pv,double w);
status_t h_remove_vertex(hlist_t *ph_list,vertex_t vertex);
hnode_t *h_search(hlist_t *ph_list,vertex_t v);
status_t h_destroy_list(hlist_t *ph_list);

void h_generic_insert(hnode_t *beg,hnode_t *mid,hnode_t *end);
void h_generic_delete(hnode_t *node);
hnode_t *h_get_node(vertex_t v,vnode_t *pv,double w);

#endif