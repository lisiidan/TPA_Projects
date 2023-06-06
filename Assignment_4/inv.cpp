#include <iostream>
#include <fstream>
#include <algorithm>
#define MOD_NUMBER 9917
#define N_MAX 100000
std::ifstream fin("inv.in");
std::ofstream fout("inv.out");

class my_data{
public:
    long long int val; //Valoarea elementului
    long long int pos; //Pozitia lui val in vectorul nesortat
    
    bool operator <(const my_data obj){
        if(val < obj.val) return 1;
        return 0;
    }
};

int comp (const void *x , const void *y)
{
    my_data *a = (my_data *)x;
    my_data *b = (my_data *)y;
    return a->val-b->val;
}

int tree[N_MAX * 4 + 5];
int pozitii[N_MAX + 5]; // pozitii[i] = pozitia elementului vec_nesortat[i] in vec_sortat
my_data vec[N_MAX + 5];



void update(int node, int l, int r, int pos, int &ans){
    if(l == r) {
        tree[node] = 1;
        return;
    }
    int m = (l + r) / 2;
    if(pos <= m){
        ans = (ans + tree[node * 2 + 1]) % MOD_NUMBER;
        update(2 * node, l, m, pos, ans);
    }
    else
    {
        update(2 * node + 1, m + 1, r, pos, ans);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];   
}

int main(){
    int n,ans = 0;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> vec[i].val;
        vec[i].pos = i;
    }
    // std::sort(vec + 1, vec + n + 1); //Nu inteleg din ce cauza nu lucreaza sortarea cu std::sort
    qsort(vec+1,n,sizeof(my_data),comp);  //Daca folosesc std::sort imi da doar 60 de puncte din 100
    for(int i = 1; i <= n; i++){          //Daca ai vreo idee as fi recunoscator sami explici in feedback :D
        pozitii[vec[i].pos] = i;
    }
    for(int i = 1; i <= n; i++){
        update(1,1,n,pozitii[i],ans);
    }
    fout << ans;
    return 0;
}