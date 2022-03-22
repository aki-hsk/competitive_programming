#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct Edge {
    int to, id;
    Edge() {}
    Edge(int to, int id):to(to), id(id) {}
};
vector<int> c;
vector<vector<Edge>> to;

bool dfs(int v, int p, int g) {
    if(v == g) return true;
    for(auto e:to[v]) {
        if(e.to == p) continue;
        if(dfs(e.to, v, g)) {
            c[e.id]++;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(m);
    for(int i=0; i<m; i++) cin >> A[i];
    to.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back({b, i});
        to[b].push_back({a, i});
    }
    c.resize(n-1);
    for(int i=0; i<m-1; i++) {
        int sv = A[i]-1, tv = A[i+1]-1;
        dfs(sv, -1, tv);
    }
    int s = 0;
    for(int i=0; i<n-1; i++) s += c[i];
    int r2 = k+s;
    if(r2 < 0 || r2 > s*2 || r2%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int r = r2/2;
    vector<mint> dp(r+1);
    dp[0] = 1;
    for(int x:c) {
        for(int i=r-x; i>=0; i--) dp[i+x] += dp[i];
    }
    cout << dp[r].val() << endl;
    return 0;
}

