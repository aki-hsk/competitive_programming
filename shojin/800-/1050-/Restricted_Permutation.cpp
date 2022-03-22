#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// トポロジカルソート
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n);
    vector<vector<int>> g(n);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        indeg[b]++;
        g[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=0; i<n; i++) {
        if(!indeg[i]) heap.push(i);
    }
    vector<int> ans;
    while(!heap.empty()) {
        int v = heap.top(); heap.pop();
        ans.push_back(v);
        for(auto nv:g[v]) {
            indeg[nv]--;
            if(!indeg[nv]) heap.push(nv);
        }
    }

    if(ans.size() != n) cout << -1 << endl;
    else {
        for(int i=0; i<n; i++) {
            cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}