#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double cut_rod(double *p,size_t n);
double max_val(double v1,double v2);

int main(void){
    double p[] = {
        0.0,1.0,5.0,8.0,9.0,10.0,
        17.0,17.0,20.0,24.0,30.0
    };

    double q = cut_rod(p,10);
    printf("q = %.1lf ",q);
    return(0);
}

double cut_rod(double *p,size_t N){
    size_t i;
    double q = -INFINITY ;
    
    if(N == 0)
       return p[N];

    for(i = 1;i <= N;++i){
        q = max_val(q,p[i] + cut_rod(p,N - i));
    }
   return(q);
}

double max_val(double v1 ,double v2){
    if(v1 > v2)
       return v1 ;
    else 
       return v2 ;
}
