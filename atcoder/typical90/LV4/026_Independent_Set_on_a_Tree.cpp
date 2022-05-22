#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g;
void dfs(int v, int p, vector<vector<int>> &depth, int d) {
  depth[d].push_back(v);
  for(auto nv:g[v]) {
    if(nv == p) continue;
    dfs(nv, v, depth, d+1);
  }
}

int main() {
  int n;
  cin >> n;
  g.resize(n);
  vector<vector<int>> depth(n);
  for(int i=0; i<n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1, depth, 0);

  int cnt = 0;
  int even = 0, odd = 0;
  for(int i=0; i<n; i++) {
    for(auto nv:depth[i]) {
      if(i % 2 == 0) even++;
      else odd++;
    }
  }

  for(int i=((odd > even) ? 1 : 0); i<n; i+=2) {
    for(auto nv:depth[i]) {
      cout << nv + 1 << " ";
      cnt++;
      if(cnt == n/2) return 0;
    }
  }
}