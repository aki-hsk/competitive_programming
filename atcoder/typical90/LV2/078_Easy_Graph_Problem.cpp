#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  for(int i=0; i<n; i++) {
    int cnt = 0;
    for(int j=0; j<g[i].size(); j++) {
      if(i > g[i][j]) cnt++;
    }
    if(cnt == 1) ans++;
  }
  cout << ans << endl;
}