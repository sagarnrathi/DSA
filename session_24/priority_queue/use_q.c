#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "prioque.h"

int main(void){
    prio_q_t *p_prio_q  = NULL ;
    data_t data,min_data ,max_data ;
    status_t status ;

    p_prio_q = create_prio_q();

    for(int i = 0;i<10;i++){
        data = rand();
        status = prio_enq(p_prio_q,data);
        printf("added %d to q \n",data);
    }

    status = prio_max_deq(p_prio_q,&max_data);
    printf("Max Data = %d\n", max_data); 

    status = prio_min_deq(p_prio_q,&min_data);
    printf("min data = %d \n",min_data);

    while(
        is_prio_q_empty(
            p_prio_q
        ) != TRUE
    )
    {
        status = prio_max_deq(
            p_prio_q, 
            &max_data
        ); 
        assert(status == SUCCESS); 
        printf(
            "Next Max Data = %d\n", 
            max_data
        ); 
    }

    status = destroy_prio_q(&p_prio_q); 
    assert(
        status == SUCCESS && 
        p_prio_q == NULL
    ); 

    exit(EXIT_SUCCESS); 
}