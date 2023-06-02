#include <iostream>
#include <fstream>
#define MOD_NUMBER 1999999973
#define ll long long
std::ifstream fin("lgput.in");
std::ofstream fout("lgput.out");
unsigned ll int my_pow(unsigned ll int N,unsigned ll int P){

    unsigned ll int t = 1;
    while(P > 0){
        if(P % 2 == 1) t = (t * N) % MOD_NUMBER;
        N = (N*N) % MOD_NUMBER;
        P /= 2;
    }
    return t % MOD_NUMBER   ;
}

int main(){
    unsigned ll int N,P;
    fin >> N >> P;
    fout << my_pow(N,P);
    return 0;
}