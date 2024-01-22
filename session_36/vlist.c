#include"vlist.h"
#include "h_hashq.h"

vlist_t *v_create_list(){
    vlist_t *pv_list = NULL ;
    pv_list = (vlist_t *) xmalloc(sizeof(vlist_t));
    pv_list -> v = -1 ;
    pv_list ->p_adj_hashq = NULL ;
    pv_list ->color = WHITE;
    pv_list -> prev = pv_list ;
    pv_list -> next = pv_list;

    return(pv_list);
}

vnode_t *v_search(vlist_t *pv_list,vertex_t v){
    vnode_t *pv_run = NULL ;
    for(pv_run = pv_list->next;pv_run != pv_list;pv_run = pv_run -> next)
        if(pv_run -> v == v)
            return(pv_run);
    return (NULL);
}

status_t v_insert_end(vlist_t *pv_list,vertex_t v)
{
   v_generic_insert(pv_list->prev,v_get_node(v),pv_list);
   return(SUCCESS);
}

void v_generic_insert(vnode_t *p_beg,vnode_t *p_mid,vnode_t *p_end){
    p_mid -> next = p_end ;
    p_mid -> prev = p_beg;
    p_end -> prev = p_mid ;
    p_beg -> next = p_mid;
}

vnode_t *v_get_node(vertex_t v){
    vnode_t *pv = NULL ;
    pv = (vnode_t *) xmalloc(sizeof(vnode_t));
    pv -> v = v ;
    pv -> p_adj_hashq = h_create_hashq(H_BUCKET_SIZE);
    pv -> color = WHITE ;
    
    return(pv);
}