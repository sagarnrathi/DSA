#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"rb_tree.h"

int main(void){

    rbtree_t *p_rb = NULL ;
    status_t status ;
    int i;
    data_t arr[500] ;

    for(i = 0 ;i < 500; ++i)
        arr[i] = rand();

    p_rb = create_rbtree();
    puts("calling insert");
    for(i = 0 ; i < 500;++i)
        assert(insert_into_rbtree(p_rb,arr[i]) == SUCCESS);
    printf("H = %d \n",get_rb_height(p_rb));
    inorder_walk(p_rb);

}