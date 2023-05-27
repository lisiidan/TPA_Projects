#include <stdio.h>
#include <stdlib.h>
float f(float x){
    return x*x-2;
}

float find_radacina_f(float a, float b, float TOL){
    float fa = f(a), fb = f(b);
    if(fa-fb < TOL){
        return a;
    }
    float c = a/2+b/2;
    float fc = f(c);
    if(fa * fc < 0){
        return find_radacina_f(a,c,TOL);
    }
    if(fb * fc < 0){
        return find_radacina_f(c,b,TOL);
    }
    printf("Functia f(x) nu are radacina pe intervalul dat\n");
    exit(0);
}

int main(){
    const float a = -2.0, b = 0.0, TOL = 0.0001;
    printf("Radacina functiei f in intervalul dat este %f\n",find_radacina_f(a,b,TOL));
    return 0;
}