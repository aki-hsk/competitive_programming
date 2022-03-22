#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));

    ll sum = 0, ans = 0;
    for(int i=0; i<N; i++) {
        ans += A[i] * i - sum;
        sum += A[i];
    }
    cout << ans << endl;
}
