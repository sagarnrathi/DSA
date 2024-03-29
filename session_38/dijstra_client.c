#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

#define NR_INIT_VERTICES 8
#define NR_INIT_EDGES 12

struct edge{
    vertex_t v_start;
    vertex_t v_end;
    double w ;
} ;

int main(){
    
    graph_t *g = NULL ;
    vertex_t v  ;
    
    int i;

    struct edge e[] = {
                      {1,6,2.0},{1,2,1.0},{2,7,5.0},{2,3,2.0},
                      {6,7,3.0},{5,7,2.0},{3,7,1.0},{7,8,3.0},
                      {3,8,3.0},{5,8,4.0},{5,4,2.0},{3,4,1.0}
    };

    g = create_graph();
    
    for(v = 1; v <= NR_INIT_VERTICES;v++)
              add_vertex(g,v);

    return 0;
}