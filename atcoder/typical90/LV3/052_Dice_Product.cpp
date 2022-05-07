#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(6));
  for(int i=0; i<n; i++) {
    for(int j=0; j<6; j++) cin >> a[i][j];
  }
  long long ans = 1;
  for(int i=0; i<n; i++) {
    long long sum = 0;
    for(int j=0; j<6; j++) {
      sum += a[i][j];
    }
    ans *= sum;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}