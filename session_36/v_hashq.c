#include "vlist.h"
#include "v_hashq.h"

vhashq_t *v_create_hashq(ssize_t bucket_size){

   vhashq_t *pv_hashq = NULL ;
   ssize_t i ;
   assert(bucket_size > 0) ;

   pv_hashq = (vhashq_t*)xmalloc(sizeof(vhashq_t)); 

   pv_hashq -> bucket_size = bucket_size ;
   
   pv_hashq -> ppv_head_node = (vlist_t **) xmalloc(bucket_size * sizeof(vlist_t *));
   
   for(i = 0 ; i < bucket_size;i++)
       pv_hashq -> ppv_head_node[i] = v_create_list();
   
    return(pv_hashq);
   
}

vnode_t *v_search_hashq(vhashq_t *pv_hashq,vertex_t v){
    
    return v_search(pv_hashq -> ppv_head_node[v %pv_hashq->bucket_size],v);

}

status_t v_add_hashq(vhashq_t *pv_hashq,vertex_t v){
    return v_insert_end(pv_hashq ->ppv_head_node[v % pv_hashq -> bucket_size],v);
}