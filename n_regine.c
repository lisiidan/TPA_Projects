#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool se_bat(int poz, int tabla[]){
    for(int i = 1; i < poz; i++){
        if(tabla[poz]==tabla[i])return true; // daca se afla pe aceeasi coloana => se bat
        if(abs(poz-i) == abs(tabla[poz]-tabla[i])) return true; // daca se afla pe aceeasi diagonala => se bat
    }
    return false;
}


void bkt(int poz,int tabla[],int n, int *rs){
    if(poz == n+1){
        (*rs)++;
    } else
    {
        for(int i = 1; i <= n; i++){
            tabla[poz] = i;
            if(!se_bat(poz,tabla)){
                bkt(poz+1,tabla,n,rs);
            }    
        }
    }
}

int main()
{
    int n,rs = 0;
    scanf("%d",&n);
    int tabla[n+1];
    bkt(1,tabla,n,&rs);
    printf("%d\n",rs);
    return 0;
}