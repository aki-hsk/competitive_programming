#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  long long tot = accumulate(a.begin(), a.end(), 0LL);
  if(tot % 10 != 0) {
    cout << "No" << endl;
    return 0;
  }

  vector<int> b = a;
  for(int i=0; i<n; i++) a.push_back(b[i]);
  n = a.size();
  long long sum = 0;

  int right = 0;
  for(int i=0; i<n; i++) {
    while(right < n && sum + a[right] <= tot / 10) {
      sum += a[right];
      right++;
    }
    if(sum == tot / 10) {
      cout << "Yes" << endl;
      return 0;
    }
    sum -= a[i];
  }
  cout << "No" << endl;
  return 0;
}