#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> g;

int bfs(int s, vector<int>& dist) {
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto nv:g[v]) {
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return max_element(dist.begin(), dist.end()) - dist.begin();
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

    vector<int> dist1(n, -1), dist2(n, -1);
    int a = bfs(0, dist1);
    int b = bfs(a, dist2);
    cout << dist2[b] + 1 << endl;
}