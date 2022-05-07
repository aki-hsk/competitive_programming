#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  for(int i=0; i<n; i++) cin >> c[i];

  vector<int> mod_a(46), mod_b(46), mod_c(46);
  for(int i=0; i<n; i++) {
    mod_a[a[i]%46]++;
    mod_b[b[i]%46]++;
    mod_c[c[i]%46]++;
  }

  long long ans = 0;
  for(int i=0; i<46; i++) {
    for(int j=0; j<46; j++) {
      for(int k=0; k<46; k++) {
        if((i + j + k) % 46 != 0) continue;
        ans += (long long)mod_a[i] * mod_b[j] * mod_c[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}