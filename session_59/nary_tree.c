#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define NR_ELEMENT 14
#define ARY 3

typedef long long int ssize_t ;

struct node{
    int* D; 
    ssize_t DN; 
    ssize_t last_index; 
    struct node** L; 
    ssize_t LN; 
}; 

struct nary_tree{
    struct node* root_node; 
    ssize_t ary; 
    ssize_t nr_elements; 
}; 


struct nary_tree *create_nary_tree(ssize_t ary);
int insert_nary_tree(struct nary_tree *p,int new_data);
void inorder_nary(struct nary_tree *p_nary_tree);
int search_nary(struct nary_tree *p_tree,int search_data);
ssize_t height_nary_tree(struct nary_tree *p_tree);
void destroy_nary_tree(struct nary_tree *p_tree);

ssize_t height_nodelevel(struct node *p);
struct node *search_nodelevel(struct node *p_node,int new_data);
void insert_in_nonfull_node(struct node*p,int new_data);
void nary_inorder_nodelevel(struct node *p);
struct node *get_node(ssize_t  DN);
void destroy_nodelevel(struct node *p);

int main(void){
    int *data = (int *) calloc(NR_ELEMENT,sizeof(int));
    assert(data != NULL);
    srand(0);
    int i;
    int status ;
    for(i = 0 ; i < NR_ELEMENT;++i){
        data[i] = rand();
        printf("data = %d \n ",data[i]);
    }

    struct nary_tree *p_nary_tree = create_nary_tree(ARY);
    

    for(i = 0;i<NR_ELEMENT;++i){
        status =  insert_nary_tree(p_nary_tree,data[i]);
        assert(status == SUCCESS);
    }
    inorder_nary(p_nary_tree);   
}

struct nary_tree *create_nary_tree(ssize_t ary){
    struct nary_tree *p = NULL ;

    assert(ary > 2);

    p = (struct nary_tree *) calloc(1,sizeof(struct nary_tree));
    assert(p!=NULL);
    p->ary = ary ;
    return(p);
}

int insert_nary_tree(struct nary_tree *p,int new_data){
    
    ssize_t i;
    ssize_t index;
    struct node *p_run = NULL ;
    
    if(p-> root_node == NULL){
        p -> root_node = get_node(p->ary -1 );
        insert_in_nonfull_node(p -> root_node,new_data);
        return(SUCCESS);
    }

    p_run = p->root_node;
    while(TRUE){
        if(p_run -> last_index  < p_run -> DN){
            insert_in_nonfull_node(p_run,new_data);
            return(SUCCESS);
        }

        if(new_data < p_run-> D[0])
           index = 0 ;
        else if (new_data > p_run -> D[p_run -> DN -1 ])
            index = p_run -> LN -1 ;
        else {
            i = 0 ;
            while(i < p_run -> DN -1){
                if(new_data > p_run -> D[i] &&  new_data < p_run-> D[i +1 ]){
                    index = i + 1 ;
                    break;
                }
                i = i + 1 ;
            }
        }    

        if(p_run -> L[index] == NULL)
            p_run-> L[index] = get_node(p -> ary -1 );
        p_run = p_run  -> L[index];
    }

}

struct node *get_node(ssize_t DN){
    struct node *p = NULL ;
    assert(DN >= 1);
    p = (struct node *)malloc(sizeof(struct node));
    assert(p!=NULL);
    p -> DN  =  DN ;
    p -> LN = DN + 1 ;

    p-> D = (int *) calloc(p -> DN,sizeof(int));
    assert(p->D != NULL);

    p-> L = (struct node **)calloc(p -> LN,sizeof(struct node *));
    assert(p -> L != NULL);
    p-> last_index = 0;
    return(p);
}

void insert_in_nonfull_node(struct node *p_node,int new_data){
    ssize_t i;
    assert(p_node -> last_index < p_node -> DN);
    i = p_node -> last_index -1 ;
    while( i > -1 && p_node -> D[i] > new_data){
        p_node -> D[i + 1] = p_node -> D[i];
        i = i -1 ;
    }

    p_node -> D[i + 1] = new_data;
    p_node -> last_index += 1 ;
}

void nary_inorder_nodelevel(struct node *p){
        ssize_t i;
        if(p == NULL)
           return  ;

        for(i = 0 ;i < p -> last_index;++i){
            nary_inorder_nodelevel(p-> L[i]);
            printf("[%d] <->",p-> D[i]);
        }
        nary_inorder_nodelevel(p->L[p->last_index]);

}

void inorder_nary(struct nary_tree *p_nary_tree){
    printf("[START] <->");
    nary_inorder_nodelevel(p_nary_tree -> root_node);
    printf("[END]\n");
}