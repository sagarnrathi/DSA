#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void *xcalloc(size_t number_of_elements,size_t size_of_element);

int main(void){
    struct node *pA = NULL ;
    struct node *pB = NULL;
    struct node *pC = NULL;
    struct node *pD = NULL;
    struct node *prun = NULL;
    struct node *prun_next = NULL;
    
    pA = (struct node*) xcalloc(1,sizeof(struct node));
    pB = (struct node*) xcalloc(1,sizeof(struct node));
    pC = (struct node*) xcalloc(1,sizeof(struct node));
    pD = (struct node*) xcalloc(1,sizeof(struct node));

    pA -> data = 10;
    pB-> data = 20;
    pC -> data = 30;
    pD -> data = 40;
    pA -> next = pB;
    pB -> next = pC;
    pC ->next = pD;
    pD -> next = NULL;

    prun  = pA;

    while(prun -> next != NULL)
    {
        printf(" %d->",prun->data);
        prun = prun ->next ;
    }
    prun = pA ;
    while(prun -> next != NULL)
    {
        prun_next = prun ->next;
        free(prun);
        prun = prun_next -> next;

    }

}

void *xcalloc(size_t number_of_elements,size_t size_of_element){
    void *p = NULL;
    p = calloc(number_of_elements,size_of_element);
    if(p == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
}