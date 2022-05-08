#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  a.push_back(l);

  int left = 0, right = 1e9;
  while(right - left > 1) {
    int mid = (right + left) / 2;
    int cnt = 0, cur = 0;
    for(int i=0; i<n; i++) {
      if(a[i] - cur >= mid && cnt < k) {
        cnt += 1;
        cur = a[i];
      }
    }
    if(cnt < k || a.back() - cur < mid) right = mid;
    else left = mid;
  }
  cout << left << endl;
  return 0;
}