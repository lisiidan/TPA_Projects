#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_ok(int *stiva, int varf_stiva, int k){
    for(int i = 0; i < varf_stiva -1; i++){
        for(int j = i + 1; j < varf_stiva; j++){
            if(stiva[i] == stiva[j])
                return false;
        }
    }
    return true;
}

void print_combinari(int n, int k, int *A, int *stiva, int varf_stiva, int varf_A){
    if(varf_stiva == k){
        for(int i = 0; i < varf_stiva; i++){
            printf("%d ",stiva[i]);
        }
        printf("\n");
    } else
    {
        varf_stiva++;
        for(int i = varf_A; i < n; i++){
            stiva[varf_stiva-1] = A[i];
            if(is_ok(stiva,varf_stiva,k)){
                varf_A++;
                print_combinari(n,k,A,stiva,varf_stiva,varf_A);
            }
        }
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int A[n],stiva[n],varf_stiva = 0,varf_A = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    print_combinari(n,k,A,stiva,varf_stiva,varf_A);
    return 0;
}