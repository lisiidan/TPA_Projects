#include <iostream>
#include <fstream>
#include <algorithm>
#define N_MAX 100001
std::ifstream fin("permutariab.in");
std::ofstream fout("permutariab.out");

long long int tree[N_MAX * 4 + 5];
int pozitii[N_MAX + 5]; // pozitii[i] = pozitia elementului B[i] in A
int A[N_MAX + 1], B[N_MAX + 1];



void update(int node, int l, int r, int pos, long long int &ans){
    if(l == r) {
        tree[node] = 1;
        return;
    }
    int m = (l + r) / 2;
    if(pos <= m){
        ans = (ans + tree[node * 2 + 1]);
        update(2 * node, l, m, pos, ans);
    }
    else
    {
        update(2 * node + 1, m + 1, r, pos, ans);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];   
}

int main(){
    long long int n,ans = 0,temp;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> temp;
        A[temp] = i;
    }
    for(int i = 1; i <= n; i++){
        fin >> B[i];
    }
    for(int i = 1; i <= n; i++){          
        pozitii[i] = A[B[i]];
    }
    for(int i = 1; i <= n; i++){
        update(1,1,n,pozitii[i],ans);
    }
    fout << ans;
    return 0;
}