#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double memoized_cut_rod(double *p,size_t n);
double max_val(double v1,double v2);
double aux_memoized_cut_rot(double *p,double *r,size_t n);

int main(void){
    double p[] = {
        0.0,1.0,5.0,8.0,9.0,10.0,
        17.0,17.0,20.0,24.0,30.0
    };

    double q = memoized_cut_rod(p,10);
    printf("q = %.1lf \b",q);

    return(0);
}

double memoized_cut_rod(double *p,size_t n){
    double *r = (double *) calloc(n+1,sizeof(double));
    size_t i;

    for(i = 0;i <=n ;++i)
        r[i] = -INFINITY ;
    
    double max_r  = aux_memoized_cut_rot(p,r,n);
    free(r);
    r = NULL ;
    return(max_r);
}

double aux_memoized_cut_rot(double *p,double *r,size_t n){
    double q ;
    size_t i;
    
    if(r[n] >= 0.0)
        return r[n];

    if(n == 0){
        r[0] = 0.0 ;
        return p[0];
    }

    if(r[n] == -INFINITY){
        q = -INFINITY ;
        for(i = 1;i <= n;++i)
            q = max_val(q,p[i]+aux_memoized_cut_rot(p,r,n - i));
        r[n] = q ;
        return(q);
    }
}

double max_val(double val1,double val2){
    if(val1 > val2)
        return val1;
    else 
       return val2;
}