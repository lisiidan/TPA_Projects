#include <iostream> 
#include <fstream>
#include <cmath>
#define ll long long
std::ifstream fin("functii.in");
std::ofstream fout("functii.out");
#define MOD_NUMBER 30103

unsigned int my_pow(unsigned ll int N,unsigned ll int P){

    unsigned ll int t = 1;
    while(P > 0){
        if(P % 2 == 1) t = (t * N) % MOD_NUMBER;
        N = (N*N) % MOD_NUMBER;
        P /= 2;
    }
    return t % MOD_NUMBER   ;
}

ll int inv(int A, int N){
    ll int r[2],x[2],y[2],q,temp;
    r[0] = A; r[1] = N;
    x[0] = 1; x[1] = 0;
    y[0] = 0; y[1] = 1;
    while(r[1] != 0)
    {
        //std::cout << "\n\n==== Pasul " << contor << " ====\nq = ";
        q = r[0] / r[1];
        //std::cout << q << "\n";
        temp = r[1];
        r[1] = r[0] - q * r[1];
        r[0] = temp;
        //std::cout << "r = " << r[1] << "\n";
        temp = x[1];
        x[1] = x[0] - q * x[1];
        x[0] = temp;
        //std::cout << "x = " << x[1] << "\n";
        temp = y[1];
        y[1] = y[0] - q * y[1];
        y[0] = temp; 
        //std::cout << "y = " << r[1] << "\n";
    }
    while(x[0] < 0){
        x[0] += N;
    }
    return x[0];
}

ll int factorial(const ll int x){
    int ans = 1;
    for(int i = 2; i <= x; i++){
        ans = i * ans % MOD_NUMBER;
    }
    return ans;
}

ll int combinari(int n, int s){
    return (factorial(n) * inv(factorial(s),MOD_NUMBER)  * inv(factorial(n-s),MOD_NUMBER) ) % MOD_NUMBER;
}

int main(){
    int n,s;
    fin >> n >> s;
    fout << (( my_pow(2,s) - 2) % MOD_NUMBER * combinari(n,s) % MOD_NUMBER) % MOD_NUMBER;
    return 0;
}