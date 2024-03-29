#include"graph.h"

typedef struct edge{
    vertex_t v_start;
    vertex_t v_end;
} edge_t;

void normal_test(void);
void extreme_test(void);

int main(void){
    #ifndef NORMAL_TESTING 
    normal_test();
    #endif;

    //#ifndef EXTREME_TEST 
    //extreme_test();
   // #endif;

    return (EXIT_SUCCESS);
}

void normal_test(void){
    vertex_t v[] = {1,2,3,4,5,6,7,8 };

    size_t nr_vertices  = sizeof(v)/sizeof(v[0]);
    edge_t E[] = {
        {1,2},{2,3},{3,4},{4,5},{5,6},
        {6,7},{7,8},{8,1},{1,3},{3,8},
        {8,4},{4,7},{7,5}
    };

    size_t nr_edges = sizeof(E) / sizeof(E[0]);
    size_t i ;
    status_t status ;
    graph_t *g = create_graph();

    for(i = 0 ; i< nr_vertices;i++){
        status = add_vertex(g,v[i]);
        assert(status == SUCCESS);
    }

    
}