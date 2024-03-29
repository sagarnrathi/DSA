#ifndef _PRIO_QUEUE_H
#define _PRIO_QUEUE_H

#include"dcll.h"

#define PRIO_Q_EMPTY LIST_EMPTY
typedef dcll_t prio_q_t  ;

prio_q_t *create_prio_q(void);

status_t prio_enq(prio_q_t *p_prio_q,data_t new_data);

status_t prio_min_deq(prio_q_t *p_prio_q,data_t *new_data);

status_t prio_max_deq(prio_q_t *p_prio_q,data_t *new_data);

status_t is_prio_q_empty(prio_q_t *p_prio_q);

status_t destroy_prio_q(prio_q_t ** pp_prio_q);

#endif  /*_PRIO_QUEUE_H*/