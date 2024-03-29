#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h>
#include <time.h> 

#include "avl.h"

#define CAP 100
#define NR_NODES 10

data_t arr[NR_NODES]; 

int main(void){
    avl_tree_t *p_avl_tree  = NULL ;
    int i;
    status_t status ;

    time_t t_start,t_end,t_acc;

    for(i= 0 ; i< NR_NODES;++i)
       arr[i] = rand() %CAP ;
    p_avl_tree = create_avl_tree();
    for(i = 0 ; i < NR_NODES ;++i){
        status = insert_into_avl_tree(p_avl_tree,arr[i]);
        assert(status == SUCCESS) ;
    }
    
    inorder_walk(p_avl_tree);
    printf("NR_NODES = %d H %lu \n",NR_NODES,get_height_of_avl_tree(p_avl_tree));
    for(i = 0 ;i < NR_NODES ; i++){
        t_start = time(0);
        status = remove_data_from_avl_tree(p_avl_tree,arr[i]);
        t_end = time(0);
        assert(status == SUCCESS);
        printf("%d : deleted node = %d remainin node : %d maxheight : %d current height = %d \n",
             i,
             arr[i],
             NR_NODES -i + 1,
             (int)floor(1.44*log2(NR_NODES -i +1)),
             get_height_of_avl_tree(p_avl_tree));
             puts("-----------------");
    }
    
}