#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "graph.h"
#include<assert.h>

graph_t *create_graph(void){
    graph_t *g = (graph_t *)xcalloc(1,sizeof(graph_t));
    g -> pv_list = (vnode_t *) xcalloc(1,sizeof(graph_t));
    g -> pv_list -> ph_list = NULL ;
    g -> pv_list -> next = g-> pv_list;
    g -> pv_list -> prev = g -> pv_list;
    
    g -> pv_list -> v = -1;

    g -> nr_vertices = 0;
    g -> nr_edges = 0 ;
    
    return(g);
}

ret_t add_vertex(graph_t *g,vertex_t v){
    
    vnode_t *pv_node = search_node_v(g->pv_list,v);

}

vnode_t *search_node_v(vlist_t *pv_list,vertex_t v_search){
    vnode_t * pv_run  = NULL ;

    for(pv_run = pv_list -> next; pv_run != pv_list;pv_run = pv_run -> next)
       if(pv_run -> v == v_search)
          return(pv_run);
    return NULL ;
}




void *xcalloc(size_t nr,size_t size_per_item){
    void *p = NULL ;
    p = calloc(nr,size_per_item);
    assert(p);
    return(p);
}