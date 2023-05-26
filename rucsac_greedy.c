#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int W,P; //Greutatea, Profitul, Raportul
    float R;
}object;

int compar(const void* elem1, const void* elem2){
    object e1 = *(const object*) elem1;
    object e2 = *(const object*) elem2;
    if(e1.R < e2.R) return -1;
    if(e1.R > e2.R) return 1;
    return 0;
}

int main(){
    int n,g;
    scanf("%d%d",&n,&g);
    object backpack[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d",&backpack[i].W,&backpack[i].P);
        backpack[i].R = (float) backpack[i].P / backpack[i].W;
    }
    qsort(backpack,n,sizeof(backpack[0]),compar);
    int current_weight = 0, i = n-1, max_profit = 0;
    while(i >= 0){
        if(backpack[i].W + current_weight <= g){
            current_weight += backpack[i].W;
            max_profit += backpack[i].P;
            i--;
        } 
        else
            break;
    }
    printf("%d\n", max_profit);
    return 0;
}