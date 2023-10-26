#include<stdio.h>
#include<stdlib.h>
#include"array.h"

int main(void)
{
    array_t *pa = NULL;
    index_t  index;
    data_t data;
    status_t status;
    ssize_t N = 8;
    
    pa = create_array(N);
    for(index = 0;index < N;index++)
        status = set(pa,index,(1 + index)* 100);
    show(pa,"after setting");

    status = get(pa,4,&data);
    printf("pa[4] = %d \n",data);
  
     for(index = 0; index < size(pa); ++index)
        set(pa, index, rand()) ; 
    
    show(pa,"before sort");
    sort(pa);
    show(pa,"after sort");
    index = search(pa,data);
    printf("%d is found at index %lld \n",data,index);

    status  = destroy_array(&pa);
    return (EXIT_SUCCESS);
}