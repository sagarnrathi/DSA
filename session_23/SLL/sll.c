#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

sll_t* create_list(void){
    return (get_node(0));
}
status_t insert_start(sll_t* p_list, data_t new_data){
    
    node_t *new_node = NULL ;
    node_t * new_node = get_node(new_data);
    new_node -> next = p_list->next ;
    p_list -> next = new_node;
    return(SUCCESS);
}
status_t insert_end(sll_t* p_list, data_t new_data){
    
    node_t *run = NULL ;
    run = p_list ->next;
    while(run ->next != NULL)
       run = run -> next ;
    run -> next = get_node(new_data);
    return SUCCESS;
}

status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data){
    node_t *e_node = NULL ;
    node_t *new_node = NULL;
    e_node = p_list -> next ;
    while(e_node -> next != NULL)
    {
        if(e_node -> data == e_data){
            new_node = get_node(new_data);
            new_node -> next = e_node -> next;
            e_node -> next = new_node ;
            return SUCCESS ;

        }
    }
    return LIST_DATA_NOT_FOUND ;
}
status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data){
    node_t *run = NULL;
    node_t * p_run = NULL ;
    node_t *new_node = NULL ;
    run = p_list -> next ;
    p_run = p_list ;

    while(run -> next != NULL)
    {
        if(run -> data == e_data){
            new_node = get_node(new_data);
            new_node -> next = run ;
            p_run -> next = new_node ;            
        }
        p_run = run ;
        run = run -> next;
    }

    return (LIST_DATA_NOT_FOUND);
}

status_t remove_start(sll_t* p_list){
    
    node_t * p_next = NULL ;
    
    if(p_list -> next == NULL)
        return (LIST_EMPTY);
    
    p_next = p_list -> next ;
    p_list ->next = p_next -> next ;
    free(p_next);
    p_next = NULL;
    return(SUCCESS);
} 
status_t remove_end(sll_t* p_list)
{
    node_t * run = NULL;
    node_t * p_run = NULL;
    run  =  p_list -> next ;
    p_run = p_list ;
    if(p_list -> next == NULL)
         return LIST_EMPTY;
    while(run != NULL)
    {
        p_run = run ;
        run = run -> next ;
    }
    p_run -> next = NULL;
    free(run);
    run = NULL;
}
status_t remove_data(sll_t* p_list, data_t r_data){
    node_t *run_prev = NULL ;
    node_t *run = NULL ;
    run_prev = p_list;
    run = p_list ->next ;

    while(run != NULL){
        if(run -> data == r_data)
        {
            run_prev -> next = run -> next;
            free(run);
            run = NULL;
            return SUCCESS;
        }
        run_prev = run ;
        run = run -> next;
    }
    return (LIST_DATA_NOT_FOUND);
}

status_t get_start(sll_t* p_list, data_t* p_start_data){
    if(p_list -> next == NULL)
        return LIST_EMPTY ;
    p_start_data = p_list ->next -> data ;
    return(SUCCESS);
}
status_t get_end(sll_t* p_list, data_t* p_end_data){

    if(p_list -> next == NULL)
        return LIST_EMPTY ;
    
    node_t *run = p_list -> next ;
    
    while(run -> next != NULL)
    
        run = run -> next ;
    
    *p_end_data = run -> data;
    return SUCCESS ;
}

status_t pop_start(sll_t* p_list, data_t* p_start_data){
    
    if(p_list -> next == NULL)
    
        return LIST_EMPTY ;
    
    *p_start_data = p_list ->next -> data;
    node_t *p_run = p_list -> next ;
    p_list -> next = p_run -> next ;
    free(p_run);
    p_run =NULL;
}
status_t pop_end(sll_t* p_list, data_t* p_end_data){
    if(p_list -> next == NULL)
         return LIST_EMPTY ;
    node_t *run = NULL ;
    node_t * prev_run = NULL ;
    
    run = p_list -> next ;
    prev_run = p_list ;
    
    while(run ->next != NULL)
    {
        prev_run = run;
        run = run ->next ;
    }
    
    *p_end_data = run ->data ;
    prev_run -> next = run -> next ;
    free(run);
    run = NULL ;
    
    return(SUCCESS);
}

status_t clear_list(sll_t* p_list){
    if(p_list -> next == NULL)
        return LIST_EMPTY ;
    node_t * n_run = NULL;
    node_t * run = NULL;
    run = p_list-> next ;
    n_run = NULL ;

    while(run ->next != NULL)
    {
        n_run = run ->next;
        free(run);
        run  = NULL ;
        run = n_run ->next;

    }
    p_list -> next = NULL ;
    return (SUCCESS);
}

status_t is_list_empty(sll_t* p_list)
{
    return p_list->next == NULL;
}
status_t find(sll_t* p_list, data_t f_data){
    node_t *run = NULL ;
    for(run = p_list -> next ;run != NULL; run = run -> next)
    {
        if(run -> data == f_data)
        {
            return TRUE ;
        }
    }
    return FALSE ;
}
len_t get_list_length(sll_t* p_list){
    len_t l = 0 ;
    node_t *run = p_list -> next;
    for(;run != NULL; run = run-> next){
        l = l + 1;
    }
    return (l);
}

void show_list(sll_t* p_list, const char* msg){
 
   if(msg)
      puts(msg);
   printf("[START]");
   node_t * run = NULL ;
   for(run = p_list-> next ;run != NULL;run = run -> next){
    pritnf("<->[%d]<->",run -> data);
   }
   puts("END");
   
}
status_t destroy_list(sll_t** pp_list){
    sll_t * p_list  = NULL;
    node_t * run = NULL ;
    node_t * next_run = NULL ;
    p_list = *pp_list ;
    run = p_list -> next ;
    while(run != NULL)
    {
        next_run = run -> next ;
        free(run);
        run = NULL ;
    }
    free(p_list);
    p_list = NULL ;
    *pp_list = NULL;
    return(SUCCESS);
}

/* Inter-list routines */
sll_t* get_concatenated_list(sll_t* p_list_1, sll_t* p_list_2){
    sll_t *p_cat_list = NULL ;
    node_t *run = NULL ;
    p_cat_list = create_list();
    for(run = p_list_1 -> next;run != NULL; run = run -> next){
        insert_end(p_cat_list,run->data);
    }

    for(run = p_list_2->next ; run != NULL;run = run ->next){
        insert_end(p_cat_list,run->data);
    }

    return(p_cat_list);
}
status_t concat_lists(sll_t* p_list_1, sll_t* p_list_2){
    node_t * run = NULL ;
    if(is_list_empty(p_list_2)==TRUE)
    {
        free(p_list_2);
        p_list_2 = NULL ;
        return (SUCCESS) ;
    }

    for(run = p_list_1 ->next ;run ->next != NULL ; run = run -> next);
    run->next = p_list_2 -> next ;
    free(p_list_2);
    p_list_2 = NULL ;
    return SUCCESS;

}
sll_t* merge_lists(sll_t* p_list_1, sll_t* p_list_2){

    sll_t * p_merged_list = NULL ;
    node_t *run_1 = NULL ;
    node_t *run_2 = NULL ;
    p_merged_list = create_list();
    run_1 = p_list_1 -> next ;
    run_2 = p_list_2 -> next ;

    while(TRUE)
    {
        if(run_1 == NULL)
        {
            while(run_2 != NULL)
            {
                insert_end(p_merged_list,run_2 -> data);
                run_2 = run_2 -> next;
            }
            break ;
        }

        if(run_2 == NULL)
        {
            while(run_1 != NULL){
                insert_end(p_merged_list,run_1->data);
                run_1 = run_1 -> next ;
            }
            break;

        }

        if(run_1 ->data < run_2 -> data){
                 insert_end(p_merged_list,run_2 ->data);
                 run_1 = run_1 ->next;
        }
        else {

            insert_end(p_merged_list,run_1 -> data);
            run_2 = run_2 ->next ;

        }
    }
   return(p_merged_list);
}
sll_t* get_reversed_list(sll_t* p_list){
    sll_t * p_reverse_list = NULL ;
    node_t * run = NULL ;
    p_reverse_list = create_list();
    run = run -> next ;
    while(run != NULL){
        insert_start(p_reverse_list,run ->data);
        run = run -> next ;
    }
    return p_reverse_list;
}

status_t reverse_list(sll_t* p_list){

     node_t * org_first  = NULL ;
     node_t * curr_first = NULL ;
     node_t * run = NULL ;
     node_t * run_next = NULL ;

     if(p_list -> next == NULL)
        return SUCCESS ;
    if(p_list -> next -> next = NULL)
       return SUCCESS ;
    
    for(run = p_list -> next ->next ;run != NULL;run = run_next)
    {
        run_next = run -> next;
        run -> next = curr_first ;
        p_list -> next =  run ;
        curr_first = run ;
    }
    org_first -> next = NULL ;
    return (SUCCESS);
  
}
static node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xmalloc(sizeof(node_t)); 
    new_node->data = new_data; 
    new_node->next = NULL; 

    return (new_node); 
}

static void* xmalloc(size_t size_in_bytes)
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(p == NULL)
    {
        fprintf(stderr, "fatal:out of virtual memory.Exiting the app\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}