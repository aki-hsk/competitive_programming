#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> g;
vector<long long> sub, ans;

// 部分木の大きさを求める
void dfs(int i, int p, int d) {
    ans[0] += d;
    for(int x:g[i]) if(x != p) {
        dfs(x, i, d+1);
        sub[i] += sub[x];
    }
}

void dfs2(int i, int p) {
    for(int x:g[i]) if(x != p) {
        ans[x] = ans[i] - 2 * sub[x] + n;
        dfs2(x, i);
    }
}

int main() {
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sub.resize(n, 1);
    ans.resize(n);

    dfs(0, -1, 0);
    dfs2(0, -1);
    for(auto x:ans) cout << x << endl;
}