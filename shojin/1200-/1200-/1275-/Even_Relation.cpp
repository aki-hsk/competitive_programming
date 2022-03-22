#include<iostream>
#include<vector>
using namespace std;
const long long INF = 1LL<<60;
struct Edge {
    int to, cost;
    Edge(int to, long long cost):to(to), cost(cost){}
};

// 任意の 2頂点 u と v について、その最小共通祖先をwとすると、uとvの距離は du + dv − 2dw と書くことができます。
//この式の第 3 項は偶数なので、duとdw の偶奇が等しいときに限り、uとwの距離は偶数になります。

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int prev = -1, long long dist = 0) {
    if(ans[v] != -1) return;
    ans[v] = dist%2;
    for(auto e:g[v]) {
        int nv = e.to;
        if(nv == prev)  continue;
        dfs(nv, v, dist+e.cost);
    }
}

int main() {
    int n;
    cin >> n;
    ans.resize(n, -1);
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(0);
    for(auto a:ans) cout << a << endl;
}