#include <iostream>
#include <fstream>
#define N_MAX 100000
std::ifstream fin("arbint.in");
std::ofstream fout("arbint.out");

int tree[N_MAX * 4 + 5];
//int V[N_MAX + 5];

// void build(int node, int l, int r){
//     if(l == r){
//         tree[node] = V[l];
//     }
//     int mid = (l + r) / 2;
//     build(2 * node, l, mid);
//     build(2 * node + 1, mid + 1, r);

//     tree[node] = (tree[2 * node] > tree[node * 2 + 1])? tree[node * 2 + 1]: tree[2 * node];
// }

void update(int node, int l, int r, int pos, int val){
    if(l == r){
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;

    if(pos <= mid){
        update(2 * node, l, mid, pos, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, r, pos, val);
    }

    tree[node] = (tree[2 * node] < tree[node * 2 + 1])? tree[node * 2 + 1]: tree[2 * node];
}

void query(int node, int l, int r, int a, int b, int &ans){
    if(a <= l && r <= b){
        ans = std::max(tree[node],ans);
        return;
    }
    int mid = (l + r) / 2;
    if(a <= mid){
        query(2 * node, l, mid, a, b, ans);
    }
    if(b > mid){
        query(2 * node + 1, mid + 1, r, a, b, ans);
    }
}

int main(){
    
    int N, M, temp;
    int type, a, b, ans;
    fin >> N >> M;
    for(int i = 1; i <= N; i++){
        fin >> temp;
        update(1,1,N,i,temp);
    }
    //build(1,1,N);
    while(M--){
        fin >> type >> a >> b;
        if(type == 1){
            update(1,1,N,a,b);
        } else
        {
            ans = 0;
            query(1,1,N,a,b,ans);
            fout << ans << std::endl;
        }
    }
    return 0;
}