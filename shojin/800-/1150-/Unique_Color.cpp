#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 木だよ!!
// オイラーツアー
vector<int> c;
vector<vector<int>> to;
vector<int> cnt;
vector<int> ans;

// pはparentのp!!
void dfs(int v, int p = -1) {
    if(!cnt[c[v]]) ans.push_back(v+1);
    cnt[c[v]]++;
    for(int u:to[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    cnt[c[v]]--;
}

int main() {
    int n;
    cin >> n;
    c = vector<int>(n);
    for(int i=0; i<n; i++) cin >> c[i];
    to.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    cnt = vector<int>(100005);
    dfs(0);
    sort(ans.begin(), ans.end());
    for(auto v:ans) cout << v << endl;
    return 0;
}