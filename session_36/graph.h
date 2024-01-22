#ifndef _GRAPH_H
#define _GRAPH_H

#include "common.h"
#include "v_hashq.h"
#include "h_hashq.h"

struct graph {
   
   vhashq_t *pv_hash;
   ssize_t nr_vertices;
   ssize_t nr_edges;

} ;

graph_t *create_graph();

status_t add_vertex(graph_t * graph,vertex_t v) ;
status_t remove_vertex(graph_t *graph,vertex_t v);
status_t add_edge(graph_t *graph,vertex_t start,vertex_t end);
status_t remove_edge(graph_t *graph,vertex_t start,vertex_t end);
void print_graph(graph_t *g,const char *msg);
status_t destroy_graph(graph_t **pp_g);
#endif