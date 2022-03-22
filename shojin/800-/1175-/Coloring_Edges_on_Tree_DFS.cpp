#include<iostream>
#include<vector>
using namespace std;

struct Edge {int to, id;};
vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int c=-1, int p=-1) {
    int k=1;
    for(auto e:g[v]) {
        if(e.to == p) continue;
        if(k == c) k++;
        ans[e.id] = k;
        k++;
        dfs(e.to, ans[e.id], v);
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n-1);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back((Edge){b, i});
        g[b].push_back((Edge){a, i});
    }
    dfs(0);
    int mx = 0;
    for(int i=0; i<n; i++) mx = max(mx, int(g[i].size()));
    cout << mx << endl;
    for(int i=0; i<n-1; i++) cout << ans[i] << endl;
    return 0;
}