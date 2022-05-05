#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<long long> A(n);
  for(int i=0; i<n; i++) cin >> A[i];

  int ans = 0;
  for(int a=0; a<n; a++) {
    for(int b=a+1; b<n; b++) {
      for(int c=b+1; c<n; c++) {
        for(int d=c+1; d<n; d++) {
          for(int e=d+1; e<n; e++) {
            if(A[a] % p * A[b] % p * A[c] % p * A[d] % p * A[e] % p == q) ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}