#include <iostream>
#include <chrono>
#include <fstream>
using namespace std::chrono;
std::ifstream fin("test_inputs/rucsac15.in");
std::ofstream fout("test_outputs/rucsac_grdy15.out");
struct object{
    int W,P; //Greutatea, Profitul, Raportul
    float R;
};

int compar(const void* elem1, const void* elem2){
    object e1 = *(const object*) elem1;
    object e2 = *(const object*) elem2;
    if(e1.R < e2.R) return -1;
    if(e1.R > e2.R) return 1;
    return 0;
}

int main(){
    auto start = high_resolution_clock::now();
    int n,g;
    fin >> n >> g;
    object backpack[n];
    for(int i = 0; i < n; i++){
        fin >> backpack[i].W >> backpack[i].P;
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
    fout << max_profit << std::endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     fout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;
    return 0;
}