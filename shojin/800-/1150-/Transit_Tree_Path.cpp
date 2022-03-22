#include<iostream>
#include<vector>
using namespace std;

// https://img.atcoder.jp/abc070/editorial.pdf
// 与えられたグラフは閉路がない連結グラフであるため（木）、異なる任意の 2 頂点間の最短経路は 1 通りに定まる！！

const int limit = 100010;
long long depth[limit];
struct Edge {
    int to;
    long long cost;
    Edge(int to, long long cost):to(to), cost(cost){}
};
vector<Edge> tree[limit];

void dfs(int v, int p, long long d) {
    depth[v] = d;
    for(auto&& e:tree[v]) {
        if(e.to == p) continue;
        dfs(e.to, v, d+e.cost);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    k--;

    // dfsでkからの最短距離を計算
    dfs(k, -1, 0);
    for(int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << depth[x] + depth[y] << endl;
    }
}