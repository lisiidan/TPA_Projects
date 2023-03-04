#include <stdio.h>
#define MAX_VALUE 1000

void print_freq_vec_bit(char vec[], int n){
    for(int i = 0; i < n; i++){
        if(vec[i] == 0) continue;
        for(int j = 0; j < 8; j++){
            if(vec[i] & (1 << j)){
                printf("%d ", i*8+j);
            }
        }
    }
    printf("\n");
}

int main(){
    int n = MAX_VALUE / 8 + 1;
    char vec[n];
    for(int i = 0; i < n; i++){ 
        vec[i] = 0;
    }
    int elem;
    while(scanf("%d",&elem) == 1){ 
        vec[elem/8] |= (1 << (elem%8));
    }
    print_freq_vec_bit(vec,n);
    return 0;
}