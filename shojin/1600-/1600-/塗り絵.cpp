#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;

vector<vector<int>> g;
long long dp[100005][2];

void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 1;
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
        dp[v][0] = ((dp[v][0] % mod) * ((dp[nv][0] + dp[nv][1]) % mod)) % mod;
        dp[v][1] = ((dp[v][1] % mod) * dp[nv][0]) % mod;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    cout << (dp[0][0] % mod + dp[0][1] % mod) % mod << endl;
}