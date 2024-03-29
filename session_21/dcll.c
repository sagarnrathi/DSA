#include<stdio.h>
#include<stdlib.h>
#include "dcll.h"



dcll_t *create_list(void)
{
     dcll_t *p_list = NULL ;
     p_list = get_node(0);
     p_list -> next = p_list;
     p_list -> prev = p_list;
     
     return(p_list);
}

status_t insert_start(dcll_t *p_list, data_t new_data)
{
    
    generic_insert(p_list,get_node(new_data),p_list -> next);    
    return SUCCESS;
}

status_t insert_end(dcll_t *p_list,data_t new_data){
    generic_insert(p_list->prev,get_node(new_data),p_list);
    return SUCCESS;
}


status_t insert_before(dcll_t *p_list,data_t e_data,data_t n_data){
    node_t * p_node = NULL ;
    p_node = search_node(p_list,e_data);
    if(p_node == NULL)
       return LIST_DATA_NOT_FOUND ;
    generic_insert(p_node -> prev , get_node(n_data),p_node);
    return SUCCESS;
}


status_t insert_after(dcll_t *p_list, data_t e_data,data_t n_data){
   
   node_t * p_node = NULL ;
   p_node = search_node(p_list,e_data);
   
   if(p_node == NULL)
     return LIST_DATA_NOT_FOUND;
   generic_insert(p_node,get_node(n_data),p_node->next);
   
   return SUCCESS;
}


status_t remove_start(dcll_t *p_list){
    if(is_list_empty(p_list))
              return (LIST_EMPTY);
    generic_delete(p_list ->next);
    return (SUCCESS);
}

status_t remove_end(dcll_t *p_list){
    if(is_list_empty(p_list))
        return (LIST_EMPTY);
    generic_delete(p_list-> prev);
    return(SUCCESS);
}


status_t remove_data(dcll_t *p_list,data_t e_data){
    node_t *p_del = NULL;
    p_del = search_node(p_list,e_data) ;
    if (p_del == NULL)
           return LIST_DATA_NOT_FOUND ;
    generic_delete(p_del);
    return(SUCCESS);
}

status_t get_start(dcll_t *p_list,data_t *p_start_data){
    if(is_list_empty(p_list))
         return LIST_EMPTY;
    *p_start_data = p_list -> next -> data;
    return(SUCCESS);
}
status_t get_end(dcll_t *p_list, data_t *p_end_data){
    if(is_list_empty(p_list))
        return LIST_EMPTY ;
    *p_end_data = p_list -> prev -> data;
    return SUCCESS;
}

status_t pop_start(dcll_t *p_list,data_t *p_data){
    
    if(is_list_empty (p_list))
        return LIST_EMPTY;
    *p_data = p_list -> next -> data ;
    generic_delete(p_list ->next);
    return SUCCESS;
}

status_t pop_end(dcll_t *p_list,data_t *p_data){
    if(is_list_empty(p_list))
        return LIST_EMPTY;
    *p_data = p_list -> prev -> data ;
     generic_delete(p_list->prev);
     return SUCCESS;
}

status_t clear_list(dcll_t *p_list){
    
    node_t * run = p_list -> next;
    node_t *next = NULL  ;
    while(run != p_list)
    {
        next = run -> next ;
        free(run);
        run =  next;
    }
    p_list -> prev = p_list ;
    p_list -> next = p_list;
    return (SUCCESS);
}

status_t is_list_empty(dcll_t *p_list){
    return(p_list -> next == p_list && p_list -> prev == p_list);       
}

status_t find(dcll_t *p_list,data_t f_data){

    if(is_list_empty(p_list))
        return LIST_EMPTY ;
    node_t * run = search_node(p_list,f_data);
    return (run !=NULL );
}

len_t get_list_lenght(dcll_t *p_list){
    node_t *run = NULL ;
    len_t len = 0 ;
    for(run = p_list;run != p_list;run = run -> next,len++);
    return(len);
}

void show_list(dcll_t *p_list,const char *msg){
    
    node_t* run = NULL; 

    if(msg)
        puts(msg); 

    printf("[START]<->"); 
    for(run = p_list->next; run != p_list; run = run->next)
        printf("[%d]<->", run->data); 
    puts("[END]"); 
}
status_t destroy_list(dcll_t **pp_list){
    clear_list(*pp_list);
    free(*pp_list);
    *pp_list = NULL ;
    return(SUCCESS);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}
static void generic_delete(node_t *beg){
    beg -> next -> prev = beg -> prev;
    beg-> prev -> next  = beg -> next;
    free(beg);
    beg = NULL; 
}
static node_t *search_node(dcll_t *p_list,data_t s_data){
    node_t * run = NULL;
    for(run = p_list->next ;run != p_list;run = run -> next)
    {
        if(run -> data == s_data) 
           return run;
    }
    return NULL;
}
static node_t *get_node(data_t new_data){
    node_t *new_node = NULL;
    new_node = (node_t *) xmalloc(sizeof(node_t));
    new_node->data = new_data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    return(new_node);
}
static void * xmalloc(size_t size_n_byte){
    void *p = NULL ;
    p  = malloc(size_n_byte);
   if(p == NULL){
    fprintf(stderr,"fatal : out of virtual mem exit app \n");
    exit(EXIT_FAILURE);
   }
   return(p);
}

dcll_t *get_concat_list(dcll_t *p_list_1,dcll_t *p_list_2){
    
    dcll_t *p_cat_list  = NULL ;
    node_t *run = NULL;
    p_cat_list = create_list();
    
    for(run = p_list_1 -> next;run != p_list_1;run = run -> next)
       insert_end(p_cat_list,run -> data);
    
    for(run = p_list_2 -> next ; run != p_list_2 ; run = run -> next)
       insert_end(p_cat_list,run->data);
    
    return(p_cat_list);

}

status_t concat_list(dcll_t *p_list_1,dcll_t *p_list_2){

    
    
    if(is_list_empty(p_list_2))
       {
        free(p_list_2);
        p_list_2  = NULL;
        return (SUCCESS);
        
       }
    
   
    p_list_2->prev->next = p_list_1; 
    p_list_2->next->prev = p_list_1->prev; 
    p_list_1->prev->next = p_list_2->next; 
    p_list_1->prev = p_list_2->prev; 


    free(p_list_2);
    p_list_2 = NULL;
    return(SUCCESS);
}

dcll_t *merge_list(dcll_t *p_list_1,dcll_t *p_list_2){
    
    dcll_t *p_merged_list = NULL;
    node_t *run_1 = NULL;
    node_t *run_2 = NULL;

    p_merged_list = create_list();
    run_1 = p_list_1 -> next;
    run_2 = p_list_2 -> next ;

    while(TRUE){

        if(run_1 == p_list_1){
           
           while(run_2 != p_list_2)
           {
            insert_end(p_merged_list,run_2 -> data);
            run_2 = run_2 -> next;
           }
           break;
        }
    
       if(run_2 == p_list_2){
        while(run_1 != p_list_1){
            insert_end(p_merged_list,run_1 ->data);
            run_1 = run_1 ->next;
        }
        break;
       }

       if(run_1 -> data <= run_2 -> data){
       
        insert_end(p_merged_list,run_1 ->data);
        run_1 = run_1 -> next;
       }

       else{
        insert_end(p_merged_list,run_2 ->data);
        run_2 = run_2 ->next;
       }
    }
    
    return(p_merged_list);
}

data_t *to_array(dcll_t *p_list,int* pn){
    node_t *run = NULL;
    data_t *p_array  = NULL ;
    len_t N = 0 ;
    int i;

    N = get_list_lenght(p_list);
    
    if(N== 0)
        return p_array;
    
    p_array = (data_t *) xmalloc(N * sizeof(data_t));

    i = 0 ;
    run = p_list -> next ;
    while(run != p_list){
        p_array[i] = run -> data ;
        i = i + 1 ;

    }
    *pn = N ;
    return(p_array);
}

dcll_t *to_list(data_t *p_array,len_t N){
    dcll_t *p_list = NULL ;
    int i ;
    p_list = create_list();
    for(i = 0;i<N;i++)
    {
        insert_end(p_list,p_array[i]);
    }
    return p_list;
}

dcll_t *get_reverse_list(dcll_t *p_list){
    dcll_t *p_reverse_list = NULL ;
    node_t *run = NULL;
    p_reverse_list = create_list();
    for(run = p_list ->next; run != p_list;run = run -> next){
       
       insert_start(p_reverse_list,run->data);
    
    }
    return(p_reverse_list);
}