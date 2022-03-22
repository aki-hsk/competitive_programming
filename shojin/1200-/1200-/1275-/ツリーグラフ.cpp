#include<iostream>
#include<vector>
using namespace std;

int n, x;
vector<vector<int>> g;
vector<int> h;

int dfs(int v, int p) {
    int res = 0;
    for(auto nv:g[v]) {
        if(nv == p) continue;
        res += dfs(nv, v);
    }
    if((res != 0 || h[v]) && v != x) res++;
    return res;
}

int main() {
    cin >> n >> x;
    x--;
    g.resize(n);
    h.resize(n);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << dfs(x, -1) * 2 << endl;
    return 0;
}