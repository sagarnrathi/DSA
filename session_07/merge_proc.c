#include <stdio.h> 
#include <stdlib.h> 

void merge_prep(int* a, int p, int q, int r); 

int main(void){
    int a[20] = {   
                    10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 
                    110, 120, 130, 140, 150, 160, 170, 180, 190, 200
                };
    merge_prep(a, 3, 8, 16); 
    return (0);  
}

/* 
    Precondition: 
        0 <= p <= q < r < N 
        a[p...q] -> SUBARRAY 1 
        a[q+1...r] -> SUBARRAY 2 
*/
void merge_prep(int* a, int p, int q, int r){

    int N = q- p;
    int * in = NULL;
    int * ne = NULL ;
    int i = 0;
    in = (int *)malloc(N * sizeof(int));
    for(i=0;i<N;i++)
       in[i] = a[p + i] ;
     for(i=0;i<N;i++)
       printf(" value is %d \n",in[i]);
    free(in);
    in = NULL;
    puts("-------------");
    N = r - q   + 1;
     ne = (int *)malloc(N * sizeof(int));
    for(i=0;i<N;i++)
       ne[i] = a[q + i] ;
     for(i=0;i<N;i++)
       printf(" value is %d \n",ne[i]);
    free(in);
    in = NULL;
    
    

}

/* 
    How to carve a subarray out of main array. 
    Let a be an array of N elements. 
    Valid index range. 0 <= i < N. 

    Let p and q be any two indices. 
    0 <= p <= q < N

    a[p..q] (including p and q)
    forms a valid subarray  
*/