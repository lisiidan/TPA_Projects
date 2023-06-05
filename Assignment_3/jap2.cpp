#include <iostream> 
#include <fstream>
#include <cmath>
#define ll long long
#define P_MAX 100007
std::ifstream fin("jap2.in");
std::ofstream fout("jap2.out");

unsigned ll int fact[P_MAX];

ll int inv(ll int A, ll int N){
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


ll int combinari(int n, int s, int P){
    if(s > n)
        return 0;
    
    return fact[n] * inv(fact[s],P) % P * inv(fact[n-s],P) % P;
}

int main(){
    ll int P,Q,A,B,ans;
    fin >> P >> Q;

    fact[0] = 1; fact[1] = 1;
    for(ll int i = 2; i <= P; i++){
        fact[i] = (fact[i-1] * i) % P;
    }

    while(Q--){
        fin >> A >> B;
        ans = 1;
        while (A > 0 || B > 0){
            ans = (ans * combinari(A % P,B % P, P)) % P;
            A /= P;
            B /= P;
        }
        fout << ans << "\n";
    }
    return 0;
}