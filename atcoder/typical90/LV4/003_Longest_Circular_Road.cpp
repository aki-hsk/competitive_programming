#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> bfs(int n, int s, vector<vector<int>> g) {
  vector<int> dist(n, -1);
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
  return dist;
}

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
  vector<int> dist_a = bfs(n, 0, g);
  int farest_point = max_element(dist_a.begin(), dist_a.end()) - dist_a.begin();
  vector<int> dist_b = bfs(n, farest_point, g);
  cout << *max_element(dist_b.begin(), dist_b.end()) + 1 << endl;
}