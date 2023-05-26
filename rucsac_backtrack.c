#include <stdio.h>
typedef struct{
    int W,P; //Greutatea, Profitul, Raportul
}object;

void bkt(int n, int g, object backpack[], int varf_stiva, int *max_profit, int current_profit, int current_weight){
    if(varf_stiva == n || current_weight == g){
        if(current_profit > *max_profit){
            *max_profit = current_profit;
        }
    } 
    else 
    {
        for(int i = varf_stiva; i < n; i++){
            if(backpack[i].W + current_weight <= g){
                bkt(n,g,backpack,i + 1,max_profit,current_profit + backpack[i].P,current_weight + backpack[i].W);
            }
        }
    }
}

int main(){
    int n,g,max_profit = 0;
    scanf("%d%d",&n,&g);
    object backpack[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d",&backpack[i].W,&backpack[i].P);
    }
    bkt(n,g,backpack,0,&max_profit,0,0);
    printf("%d\n",max_profit);
    return 0;
}