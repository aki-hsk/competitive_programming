#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];

  int div = 0;
  for(int i=0; i<n; i++) div += abs(a[i]-b[i]);
  if(div > k || (k - div) % 2 == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}