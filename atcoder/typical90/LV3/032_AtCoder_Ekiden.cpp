#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> section;
  for(int i=0; i<n; i++) section.push_back(i);
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<bool>> relation(n, vector<bool>(n, true));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    relation[x][y] = false;
    relation[y][x] = false;
  }

  int ans = (1<<30);
  do {
    bool ok = true;
    for(int i=0; i<n-1; i++) {
      if(!relation[section[i]][section[i+1]]) ok = false;
    }
    if(!ok) continue;
    int sum = 0;
    for(int i=0; i<n; i++) {
      sum += a[section[i]][i];
    }
    ans = min(ans, sum);
  } while(next_permutation(section.begin(), section.end()));

  cout << (ans == (1<<30) ? -1 : ans) << endl;
  return 0;
}