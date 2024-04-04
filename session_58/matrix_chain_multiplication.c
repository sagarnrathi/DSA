#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define N_MAX 25
#define N_ROW_COL_MAX 75

struct output{
    int* m; 
    int mRows, mCols; 
    int* s; 
    int sRows, scols; 
}; 

void input_matrix_chain_dimensions(int** pp_p, int* pN); 
void matrix_chain_multiplication(int* p, int nN, struct output* p_out); 
void print_optimal_paranthesis(struct output* p_op, int i, int j); 

int main(void){
    int* p = NULL; 
    int nN = 0; 
    int nM = 0; 
    int i; 
    struct output op; 

    memset(&op, 0, sizeof(struct output)); 
    input_matrix_chain_dimensions(&p, &nN); 
    nM = nN - 1; 

    puts("Printing the Dimensions of Matrices in the chain"); 
    printf("Number of Matrices = %d\n", nM); 
    for(i = 0; i < nM; ++i)
        printf("MATRIX:A(%d):DIM(%d x %d)\n", i, p[i], p[i+1]); 

    matrix_chain_multiplication(p, nN, &op); 
    //print_optimal_paranthesis(&op, 1, nM); 

    printf("OPTMIAL NUMBER OF OPS:%d\n", *(op.m + 0 * nM + nM-1)); 

    print_optimal_paranthesis(&op, 0, nM-1); 
    puts(""); 

    /* clean up */
    free(op.m);
    op.m = NULL; 

    free(op.s);
    op.s = NULL; 
    
    free(p); 
    p = NULL; 

    puts("END"); 

    return (EXIT_SUCCESS); 
}

void matrix_chain_multiplication(int* p, int nN, struct output* p_out){
    int nM = nN-1; /* indexed from 0 to nM-1*/
    
    int* m = NULL; 
    int mRows = nM, mCols = nM; 

    int* s = NULL; 
    int sRows = nM, sCols = nM;

    int i, j, k, length, q; 

    m = (int*)malloc(mRows * mCols * sizeof(int)); 
    if(m == NULL){
        puts("AllocationError:malloc() failed"); 
        exit(EXIT_FAILURE); 
    }
    memset(m, 0, mRows * mCols * sizeof(int)); 

    s = (int*)malloc(sRows * sCols * sizeof(int)); 
    if(s == NULL){
        puts("AllocationError:Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }
    memset(s, 0, sRows * sCols * sizeof(int)); 

    for(length = 2; length <= nM; ++length){
        for(i = 0; i < nM - length + 1; ++i){
            j = i + length - 1; 
            *(m + i * mRows + j) = INT_MAX; 
            for(k = i; k < j; ++k){
                q = *(m + i * mRows + k) + *(m + (k+1) * mRows + j)  + p[i] * p[k+1] * p[j+1]; 
                if(q < *(m + i * mRows + j)){
                    *(m + i * mRows + j) = q; 
                    *(s + i * mRows + j) = k; 
                }
            }
        }
    }

    p_out->m = m; 
    p_out->mRows = nM; 
    p_out->mCols = nM; 
    p_out->s = s; 
    p_out->sRows = nM; 
    p_out->scols = nM; 
}

void print_optimal_paranthesis(struct output* p_op, int i, int j){
    int k; 
    if(i == j)
        printf("A%d", i); 
    else{
        k = *(p_op->s + i * p_op->mRows + j); 
        printf("("); 
        print_optimal_paranthesis(p_op, i, k); 
        print_optimal_paranthesis(p_op, k+1, j); 
        printf(")"); 
    }
}

void input_matrix_chain_dimensions(int** pp_p, int* pN){
    int* p = NULL; 
    int N = 0; 
    int i; 
    int rows, cols; 

    srand(time(0)); 
    N = (2 + rand() % (N_MAX-1)); 
    
    p = (int*)malloc((N+1)*sizeof(int)); 
    if(p == NULL)
    {
        puts("AllocationError:malloc() failed"); 
        exit(EXIT_FAILURE); 
    }

    p[0] = 1 + (rand() % N_ROW_COL_MAX); 
    for(i = 1; i <= N; ++i)
        p[i] = 1 + rand() % N_ROW_COL_MAX; 

    *pp_p = p; 
    *pN = (N+1); 
}