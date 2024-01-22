#include "common.h"
#include "hlist.h"
#include "vlist.h"
#include "h_hashq.h"
#include "v_hashq.h"
#include "graph.h"

graph_t *create_graph(void){
    
    graph_t *g = NULL ;
    
    printf("v = %d , h = %d \n", V_BUCKET_SIZE,H_BUCKET_SIZE);
    g = (graph_t *)xmalloc(sizeof(graph_t));
    g -> pv_hash = v_create_hashq(V_BUCKET_SIZE);
    g -> nr_edges = 0 ;
    g -> nr_vertices = 0 ;

    return(g); 
}

status_t add_vertex(graph_t *g, vertex_t v){

   vnode_t *pv = NULL ;
    
   pv = v_search_hashq(g -> pv_hash,v);
   if(pv  != NULL)
       return(G_VERTEX_EXIST);
   g ->nr_vertices += 1;
   return(v_add_hashq(g -> pv_hash,v));

}