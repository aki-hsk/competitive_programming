#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main() {
    int n = 9;
    int m;
    cin >> m;
    vector<vector<int>> to(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    // 初期状態
    vector<int> s(n, -1);
    for(int i=0; i<n-1; i++) {
        int p;
        cin >> p;
        --p;
        s[p] = i;
    }

    // 目標状態
    vector<int> t(n, -1);
    for(int i=0; i<n-1; i++) t[i] = i;
    map<vector<int>, int> dist;
    queue<vector<int>> q;
    q.push(s);

    while(!q.empty()) {
        s = q.front(); q.pop();
        int d = dist[s];
        for(int v=0; v<n; v++) if(s[v] == -1) {
            for(int u:to[v]) {
                swap(s[u], s[v]);
                if(dist.find(s) == dist.end()) {
                    dist[s] = d + 1;
                    q.push(s);
                }
                swap(s[u], s[v]);
            }
        }
    }
    if(dist.find(t) == dist.end()) cout << -1 << endl;
    else cout << dist[t] << endl;
    return 0;
}