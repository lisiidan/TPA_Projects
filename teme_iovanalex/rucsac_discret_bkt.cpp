#include <iostream>
#include <vector>
#include <map>
#include <fstream>

std::ifstream fin("rucsac.in");
std::ofstream fout("rucsac.out");
struct obiecte{
    int profit,greutate;
};
std::vector<obiecte> rucsac;
int N, G,used_size = 0;
std::map<int, obiecte> used;

void bkt(int x, int &Pmax, int P_current, int G_current){
    if(x == N) return;
    P_current += rucsac[x].profit;
    G_current += rucsac[x].greutate;
    for(int i = x + 1; i < N; i++){
        if(G_current + rucsac[i].greutate < G) 
            bkt(i,Pmax,P_current,G_current);
        else
            if(Pmax < P_current) Pmax = P_current;
    }
    if(Pmax < P_current) Pmax = P_current;
    P_current -= rucsac[x].profit;
    G_current -= rucsac[x].greutate;
    bkt(x+1,Pmax,P_current,G_current);
}


int main(){
    fin >> N >> G;
    obiecte temp;
    for(int i = 0; i < N; i++){
        fin >> temp.greutate >> temp.profit;
        rucsac.push_back(temp);
    }
    int Pmax = -1;
    bkt(0,Pmax,0,0);
    fout << Pmax << std::endl;
    return 0;
}