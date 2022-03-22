#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> g;
vector<int> par;
vector<long long> add;

void dfs(int v, int p) {
    par[v] = p;
    if(p != -1) add[v] += add[p];
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    vector<int> a(n-1), b(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    par.resize(n, -1);
    add.resize(n);
    dfs(0, -1);

    long long offset = 0;
    int q;
    cin >> q;
    while(q--) {
        int type, id, v;
        cin >> type >> id >> v;
        id--;
        int A = a[id], B = b[id];
        if(type == 1) swap(A, B);
        if(par[B] == A) add[B] += v;
        else add[A] -= v, offset += v;
    }
    dfs(0, -1);
    for(auto v:add) cout << v + offset << endl;
}