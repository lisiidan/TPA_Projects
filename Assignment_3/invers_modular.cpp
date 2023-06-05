#include <iostream>
#include <fstream>
#define ll long long
std::ifstream fin("inversmodular.in");
std::ofstream fout("inversmodular.out");

ll int inv(int A, int N){
    int contor = 2;
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
        contor++;
    }
    while(x[0] < 0){
        x[0] += N;
    }
    return x[0];
}

int main(){
    unsigned ll int A,N;
    fin >> A >> N;
    fout << inv(A,N);
    return 0;
}   