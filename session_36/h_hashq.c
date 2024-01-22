#include "h_hashq.h"

hhashq_t *h_create_hashq(ssize_t bucket_size){
    
    hhashq_t *p_hash = NULL ;
    ssize_t i;

    assert(bucket_size > 0);
    p_hash = (hhashq_t *) xmalloc(sizeof(hhashq_t));
    p_hash ->bucket_size = bucket_size ;
    p_hash -> pp_head_node = (hlist_t **)xmalloc(bucket_size * sizeof(hlist_t *));

    for(i = 0 ; i < bucket_size ;++i)
       p_hash -> pp_head_node[i] = h_create_list();
    return(p_hash);
}