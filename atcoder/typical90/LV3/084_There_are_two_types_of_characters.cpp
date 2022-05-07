#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  long long ans = (long long)n * (n-1) / 2;

  vector<int> v;
  for(int i=0; i<n; i++) {
    int cnt = 1;
    while(i+1 < n && s[i] == s[i+1]) {
      cnt++;
      i++;
    }
    if(cnt > 1) v.push_back(cnt);
  }

  for(long long x:v) {
    ans -= x * (x-1) / 2;
  }
  cout << ans << endl;
}