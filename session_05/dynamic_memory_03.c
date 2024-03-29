#include<stdio.h>
#include<stdlib.h>

struct dynamic_array
{
    int *a;
    int N ;
};

struct dynamic_array get_dynamic_array_1(void );
struct dynamic_array * get_dynamic_array_2(void);
void get_dynamic_array_3(struct dynamic_array ** pp_dyn_arr );

int main(void){
    struct dynamic_array arr_1;
    int i;
    struct dynamic_array * p_arr = NULL;

    struct dynamic_array * p_arr_2 = NULL;
    arr_1 = get_dynamic_array_1() ;
    puts("get show release dynamic array : 1 ");
    for(i = 0;i< arr_1.N;i++)
       printf(" arr.a[%d] : %d \n",i,arr_1.a[i]);
    free(arr_1.a);
    arr_1.a = NULL ;
    arr_1.N = 0 ;

    puts("get show release dynamic array : 2");
    p_arr = get_dynamic_array_2();
    for(i = 0;i< p_arr -> N;i++)
       printf(" p_arr.a[%d] : %d \n",i,p_arr ->a[i]);
    free(p_arr -> a);
    free(p_arr);
    p_arr = NULL ;
    
    get_dynamic_array_3(&p_arr);
       puts("get show release dynamic array : 3");
    p_arr = get_dynamic_array_2();
    for(i = 0;i< p_arr -> N;i++)
       printf(" p_arr.a[%d] : %d \n",i,p_arr ->a[i]);
    free(p_arr -> a);
    free(p_arr);
    p_arr = NULL; 
    return(0);
}

struct dynamic_array get_dynamic_array_1(void){
    struct dynamic_array arr;
    int i = 0;
    arr.N = 5 ;
    arr.a = (int *) malloc(arr.N * sizeof(int));
    for(i=0;i<arr.N;i++)
        arr.a[i] = (i + 1) * 100;
    return arr;
}

struct dynamic_array * get_dynamic_array_2(void){
       int i = 0;
       struct dynamic_array * ret = NULL; 
       ret = (struct dynamic_array *) malloc(sizeof(struct dynamic_array));
       if(ret == NULL)
       {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
       }
       ret-> N = 6 ;
       ret-> a = (int *) malloc(ret -> N * sizeof(int));
       
       for(i=0;i<ret->N;i++)
          ret ->a[i] = (i + 1 ) * 50 ;
       return ret;
       
}

void get_dynamic_array_3(struct dynamic_array ** pp_dyn_arr )
{
   struct dynamic_array *p_arr = NULL;
   int i = 0 ;
   
   p_arr = (struct dynamic_array *) malloc(sizeof(struct dynamic_array));
   p_arr -> N = 7 ;
   if(p_arr == NULL)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_SUCCESS);
   }
   
   p_arr->a = (int *) malloc(p_arr -> N * sizeof(int));
   if(p_arr -> a == NULL)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
   }
   
   for(i=0;i<p_arr->N;i++)
   {
    p_arr ->a[i] = (i + 1) * 100 ;
   }
   *pp_dyn_arr = p_arr;
}