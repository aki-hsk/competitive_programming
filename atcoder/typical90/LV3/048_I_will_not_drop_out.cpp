#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  priority_queue<pair<int, int>> pq;
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    pq.push({b, i});
    mp[i] = a-b;
  }
  long long ans = 0;
  while(k--) {
    ans += pq.top().first;
    if(pq.top().second != -1) pq.push({mp[pq.top().second], -1});
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}