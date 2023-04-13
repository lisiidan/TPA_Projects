#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool is_ok(int *stiva, int varf_stiva){
    for(int i = 0; i < varf_stiva -1; i++){
        for(int j = i + 1; j < varf_stiva; j++){
            if(stiva[i] == stiva[j])
                return false;
        }
    }
    return true;
}

void print_permutari(int n, int *A, int *stiva, int varf_stiva){
    if(varf_stiva == n){
        for(int i = 0; i < varf_stiva; i++){
            printf("%d ",stiva[i]);
        }
        printf("\n");
    } else
    {
        varf_stiva++;
        for(int i = 0; i < n; i++){
            stiva[varf_stiva-1] = A[i];
            if(is_ok(stiva,varf_stiva))
                print_permutari(n,A,stiva,varf_stiva);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n],stiva[n],varf_stiva = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    print_permutari(n,A,stiva,varf_stiva);
    return 0;
}