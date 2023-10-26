#include "prioque.h"

prio_q_t *create_prio_q(void){
    return create_list();
}

status_t prio_enq(prio_q_t *p_prio_q,data_t new_data){
 
 return (insert_end(p_prio_q, new_data));

}

status_t prio_min_deq(prio_q_t *p_prio_q,data_t * p_min_data){
    return(pop_min(p_prio_q,p_min_data));
}

status_t prio_max_deq(prio_q_t *p_prio_q,data_t *p_min_data){
    return(pop_max(p_prio_q,p_min_data));
}

status_t is_prio_q_empty(prio_q_t *p_prio_q){
    return is_list_empty(p_prio_q);
}

status_t destroy_prio_q(prio_q_t ** pp_prio_q){
    return destroy_list(pp_prio_q);
}