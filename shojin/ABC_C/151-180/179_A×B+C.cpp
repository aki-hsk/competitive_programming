#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;

int main() {
	ll N;
	cin >> N;
	ll ans = 0;

    // (N-1)としておくと割り切れてしまう場合も考慮している
	for(int i=1; i<=N; i++) if((N-1)/i > 0) ans += (N-1)/i;
	cout << ans << endl;
}