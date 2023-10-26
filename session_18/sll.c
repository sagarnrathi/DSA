#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

sll_t *create_list(){
    return (get_node(0));
}

status_t insert_start(sll_t *p_list,data_t new_data){
    node_t *new_node  = NULL;
    new_node = get_node(new_data);
    new_node ->next = p_list ->next;
    p_list -> next = new_node;

    return(SUCCESS);
}

status_t insert_end(sll_t *p_list,data_t new_data){
    node_t * run = p_list->next;
    while(run ->next != NULL)
         run = run->next;
    run->next = get_node(new_data);
    
    return(SUCCESS);
}

status_t insert_after(sll_t *p_list,data_t e_data,data_t n_data){
    
    node_t *run = p_list->next;
    node_t *new_node = NULL;

    while(run != NULL){
    
        if(run -> data == e_data){
          
          new_node = get_node(n_data);
          new_node -> next = run -> next;
          run -> next = new_node ;
          return SUCCESS;
        }
    
        run = run->next;
    }
    
    return (LIST_DATA_NOT_FOUND);
}

status_t insert_before(sll_t *p_list,data_t e_data,data_t n_data){
    
    node_t *run = p_list ->next;
    node_t *prev = run;
    node_t *new = NULL;

    while(run != NULL)
    {
     
     if(run ->data == e_data)
     {
        new = get_node(n_data);
        prev -> next = new ;
        new -> next = run ;
        return SUCCESS;
     }
     prev = run ;
     run = run -> next;
      
    }
   return (LIST_DATA_NOT_FOUND);
}

status_t remove_start(sll_t *p_list)
{
    node_t * p_next =  NULL;
    p_next = p_list -> next;
    
    if(p_list -> next == NULL)
       return LIST_EMPTY ;
    p_list -> next =  p_list -> next ->next;
    free(p_next);
    p_next = NULL;
    return SUCCESS;
}

status_t remove_end(sll_t * p_list){
    if(p_list -> next == NULL)
       return LIST_EMPTY;
    
    node_t * p_run = p_list -> next ;
    node_t * p_prev = p_run;
  
    while(p_run->next != NULL)
    { 
        p_prev = p_run;
        p_run = p_run ->next;
   
    }
    
    p_prev ->next = NULL;
    free(p_run);
    p_run = NULL;
    return SUCCESS;
}

status_t remove_data(sll_t *p_list,int e_data){

    if(p_list -> next == NULL)
       return LIST_EMPTY;
    node_t * p_run  =  p_list -> next;
    node_t * p_prev = p_run;

    while(p_run != NULL)
    {
        if(p_run -> data == e_data)
        {
            p_prev -> next = p_run -> next;
            free(p_run);
            p_run = NULL;
            return SUCCESS ;
        }
        p_prev = p_run ;
        p_run = p_run ->next;

    }
    return SUCCESS;
}

void show_list(sll_t *p_list,const char *msg)
{
    node_t * run = NULL ;
    if(msg)
       puts(msg);
    
    printf("[START] -> ");
    run = p_list -> next;
    while(run != NULL)
    {
        printf("[%d] -> ",run -> data);
        run = run -> next;
    }
    puts("[END]");

}

static node_t * get_node(data_t new_data){
    node_t * new_node = NULL;
    new_node  = (node_t *)xmalloc(sizeof(node_t));
    new_node -> data  = new_data ;
    new_node -> next = NULL;
    return(new_node);
}

static void*xmalloc(size_t size_in_byte){
  
    void *p = NULL ;
    p = malloc(size_in_byte);
    
    if(p == NULL){
        fprintf(stderr,"fatal : out of virtual memory .exiting the app \n");
        exit(EXIT_FAILURE);

    }
    return(p);
}