#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

int main(void){
    vector_t *pa = NULL;
    index_t index;
    data_t data;
    status_t status;
    ssize_t N = 8;

    pa = create_array(N);
    

    for(index = 0 ;index < N;index++)
        set(pa,index,(1 + index)*100);
    show(pa,"after setting");
    status = get(pa,4,&data);
    printf("valis at index 4 is %d \n",data);

    
    for(index = 0; index < size(pa); ++index)
        set(pa, index, rand());
    show(pa,"before sort");
    sort(pa);
    show(pa,"after sort");
    destroy_array(&pa);
    pa = NULL;
    return SUCCESS;

}
