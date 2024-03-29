#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

#define EQUAL   1
#define X_MAX   2 
#define Y_MAX   3 

#define C(i, j, n)     (*((c) + (i) * (n) + (j)))
#define B(i, j, n)     (*((b) + (i) * (n) + (j)))

struct output
{
    int* p_len_arr; 
    int nr_len_arr_rows; 
    int nr_len_arr_cols; 
    int* p_subseq_arr; 
    int nr_subseq_arr_rows; 
    int nr_subseq_arr_cols; 
}; 

void lcs_length(const char* X, const char* Y, struct output* p_op); 
void print_lcs(int* p_subseq_arr, const char* X, int m, int n, int i, int j); 

int main(void)
{
    const char* X = "AXYZBPQWCLMNDXYZ"; 
    const char* Y = "PPPPAQQQBRRRRCKKKDFF"; 
    struct output op; 

    memset(&op, 0, sizeof(struct output)); 
    lcs_length(X, Y, &op); 
    if(op.p_subseq_arr == NULL || op.p_len_arr == NULL)
    {
        fprintf(stderr, "Error in algorithm\n"); 
        exit(-1); 
    }
    printf("Longest Common Subsequence is:"); 
    print_lcs(op.p_subseq_arr, X, op.nr_subseq_arr_rows, 
                op.nr_subseq_arr_cols, op.nr_subseq_arr_rows-1, 
                op.nr_subseq_arr_cols-1); 
    printf("\n"); 
    printf("Length of LCS = %d\n", 
        *(op.p_len_arr + (op.nr_len_arr_rows-1) * op.nr_len_arr_cols + op.nr_len_arr_cols-1)); 
    
    free(op.p_len_arr); 
    op.p_len_arr = NULL; 
    free(op.p_subseq_arr);
    op.p_subseq_arr = NULL; 

    exit(0);  
}

void lcs_length(const char* X, const char* Y, struct output* p_op)
{
    int m = strlen(X); 
    int n = strlen(Y); 
    int* c = NULL; /* p_len_arr */ 
    int* b = NULL; /* p_subseq_arr */ 
    int i, j; 
     
    if(m == 0 || n == 0)
    {   
        p_op->p_len_arr = NULL; 
        p_op->nr_len_arr_rows = -1; 
        p_op->nr_len_arr_cols = -1; 
        p_op->p_subseq_arr = NULL; 
        p_op->nr_subseq_arr_rows = -1; 
        p_op->nr_subseq_arr_cols = -1; 
        return; 
    }

    c = (int*)calloc((m+1)*(n+1), sizeof(int)); 
    assert(c); 
    b = (int*)calloc(m * n, sizeof(int)); 
    assert(b); 

    for(i = 0; i < m; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(X[i] == Y[j])
            {
                // C[i+1, j+1] = C[i,j] + 1
                *(c + (i+1) * (n+1) + (j+1)) = *(c + i * (n+1) + j) + 1; 
                *(b + i * n + j) = EQUAL; 
            }
            // C[i, j+1] >= C[i+1, j]
            else if(*(c + (i) * (n+1) + (j+1)) >= 
                    *(c + (i+1) * (n+1) + (j))
            )
            {
                // C[i+1, j+1] = C[i+1, j]
                *(c + (i+1) * (n+1) + (j+1)) = *(c + (i) * (n+1) + (j+1)); 
                *(b + i * n + j) = X_MAX; 
            }
            else 
            {
                // C[i+1, j+1] = C[i, j+1]
                *(c + (i+1) * (n+1) + (j+1)) =   *(c + (i+1) * (n+1) + (j)); 
                 *(b + i * n + j) = Y_MAX;    
            }
        }
    }

    p_op->p_len_arr = c; 
    p_op->nr_len_arr_rows = m+1;  
    p_op->nr_len_arr_cols = n+1; 

    p_op->p_subseq_arr = b; 
    p_op->nr_subseq_arr_rows = m; 
    p_op->nr_subseq_arr_cols = n; 
} 

void print_lcs(int* p_subseq_arr, const char* X, int m, int n, int i, int j)
{
    int* b = p_subseq_arr; 
    if(i == -1 || j == -1)
        return; 

    if(*(b + i * n + j) == EQUAL)
    {
        print_lcs(b, X, m, n, i-1, j-1); 
        printf("%c", X[i]); 
    }
    else if(*(b + i * n + j) == X_MAX)
        print_lcs(b, X, m, n, i-1, j);    
    else
         print_lcs(b, X, m, n, i, j-1);   
}

/* 
    c[i][j]
    m+1, n+1

    c + i * 

arr[3][5]
arr[m][n]
E   E   E   E   E 
E   E   E   E   E
E   E   E   E   E

c + 2 * 5 + 3 

*(c + i * n + j)
*/ 
