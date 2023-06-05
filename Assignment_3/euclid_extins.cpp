#include <iostream>
#include <fstream>
#include <algorithm>
#define ll long long
std::ifstream fin("euclid3.in");
std::ofstream fout("euclid3.out");

int euclid(int a, int b, int x[], int y[]){
    ll int r[2],q,temp;
    r[0] = a; r[1] = b;
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
        //std::cout << "y = " << y[1] << "\n";
        
    }
    return r[0];
}

int main(){
    int T,a,b,c,x[2],y[2];
    fin >> T;
    while(T--){
        fin >> a >> b >> c;
        int d = euclid(a,b,x,y);
        if(c % d)
            fout << "0 0\n";
        else
            fout << x[0] * (c/d) << " " << y[0] * (c/d) << std::endl;
    }
    return 0;
}