#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float bab_sqrt(float x, float a0, float TOL){
    float a_n = (float) 0.5 * (a0 + x/a0);
    if(fabs(a0 - a_n) < TOL) {
        return a_n;
    }
    return bab_sqrt(x,a_n,TOL);
}

int main(){
    float x,TOL;
    while (scanf("%f %f", &x, &TOL) == 2){
        printf("%f\n",bab_sqrt(x,1.0,TOL));
    }
    return 0;
}