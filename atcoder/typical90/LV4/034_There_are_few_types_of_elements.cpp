#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  int ans = 0, right = 0;
  map<int, int> mp;
  for(int left=0; left<n; left++) {
    while(right < n && mp.size() <= k) {
      if(mp.size() == k && mp.find(a[right]) == mp.end()) break;
      mp[a[right]]++;
      right++;
    }
    ans = max(ans, right - left);
    mp[a[left]]--;
    if(!mp[a[left]]) mp.erase(a[left]);
  }
  cout << ans << endl;
  return 0;
}