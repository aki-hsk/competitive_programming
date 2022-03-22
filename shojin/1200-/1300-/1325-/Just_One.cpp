#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    dsu t(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.push_back({a, b});
        t.merge(a, b);
    }

    // 頂点と辺の本数を数える
    vector<int> numV(n), numE(n);
    for(auto [a, b] : edges) {
        numE[t.leader(a)]++;
    }
    for(int i=0; i<n; i++) numV[t.leader(i)]++;
    mint ans = 1;
    for(int i=0; i<n; i++) {
        if(numV[i] == 0) continue;
        if(numV[i] != numE[i]) ans = 0;
        else ans *= 2;
    }
    cout << ans.val() << endl;
    return 0;
}