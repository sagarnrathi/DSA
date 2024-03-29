#include "common.h"

void *xmalloc(size_t number_of_bytes){
    
    void *p = NULL ;
    
    p = malloc(number_of_bytes);
    if(p == NULL)
    {
        fprintf(stderr,"malloc():fatal:out of memory \n");
        exit(EXIT_FAILURE);
    }
    return p;
}