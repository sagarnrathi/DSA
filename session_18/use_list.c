#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

int main(void){
    
    sll_t * p_list = NULL;
    status_t status ;
    p_list = create_list();
    show_list(p_list,"after creating list");

    status = insert_start(p_list,10);
    status = insert_end(p_list,20);
    status = insert_end(p_list,30);
    status = insert_end(p_list,40);
    status = insert_end(p_list,50);
    show_list(p_list,"adding 10 and 20 ");

    status = insert_after(p_list,10,15);
    status = insert_before(p_list,20,18);
    show_list(p_list,"adding 15 ,18");

    status = remove_start(p_list);
    status = remove_end(p_list);
    status = remove_data(p_list,30);
    show_list(p_list,"removed atrt and end and 30");

    
}