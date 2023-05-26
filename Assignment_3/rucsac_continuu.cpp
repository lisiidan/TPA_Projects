#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
std::ifstream fin("rucsacfr.in");
std::ofstream fout("rucsacfr.out");
class obiecte{
    public:
    float profit,greutate;
    int operator<(obiecte obj){
        if((float)obj.profit/obj.greutate < (float)profit/greutate)
            return 1;
        return 0;
    }
};

int main(){
    int N,K;
    fin >> N >> K;
    obiecte temp;
    std::vector<obiecte> rucsac;
    for(int i = 1; i <= N; i++){
        fin >> temp.greutate >> temp.profit;
        rucsac.push_back(temp);
    }
    sort(rucsac.begin(),rucsac.end());
    float profit_curent = 0,greutate_curent = 0,i = 0;
    while(greutate_curent < K && i < rucsac.size()){
        if(greutate_curent + rucsac[i].greutate <= K){
            profit_curent += rucsac[i].profit;
            greutate_curent += rucsac[i].greutate;
        }
        else
        {
            float portiune = (K - greutate_curent) * (rucsac[i].profit / rucsac[i].greutate);
            profit_curent += portiune;
            break;
        }
        i++;
    }
    fout<< std::fixed << std::setprecision(2) << profit_curent;
    return 0;
}