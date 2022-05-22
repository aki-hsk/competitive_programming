#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(1005, vector<int>(1005));
  for(int i=0; i<n; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    a[ly+1][lx+1]++;
    a[ry+1][rx+1]++;
    a[ly+1][rx+1]--;
    a[ry+1][lx+1]--;
  }

  for(int i=1; i<1001; i++) {
    for(int j=1; j<1001; j++) {
      a[i][j] += a[i][j-1];
    }
  }

  for(int j=1; j<1001; j++) {
    for(int i=1; i<1001; i++) {
      a[i][j] += a[i-1][j];
    }
  }

  vector<int> ans(n+1);
  for(int i=0; i<1001; i++) {
    for(int j=0; j<1001; j++) {
      ans[a[i][j]]++;
    }
  }
  for(int i=1; i<=n; i++) cout << ans[i] << endl;
}