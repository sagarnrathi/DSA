#include "hlist.h"

hlist_t *h_create_list(){

    hlist_t *ph_list = NULL ;
    ph_list = (hlist_t *)xmalloc(sizeof(hlist_t));
    ph_list -> v = -1 ;
    ph_list -> pv = NULL ;
    ph_list -> w = 0.0 ;
    ph_list -> next = ph_list;
    ph_list -> prev = ph_list;

    return (ph_list);
}