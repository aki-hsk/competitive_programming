#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(0);
    vector<int> ans;
    vector<bool> vis(n);
    while(!q.empty()) {
        int v = q.top(); q.pop();
        vis[v] = true;
        ans.push_back(v+1);
        for(auto nv: g[v]) {
            if(vis[nv]) continue;
            q.push(nv);
        }
    }
    for(int i=0; i<n; i++) {
        if(i != 0) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    cout << endl;
}