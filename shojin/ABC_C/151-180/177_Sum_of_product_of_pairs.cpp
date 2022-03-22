#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll res = 0;
    ll sum = A[0];

    for(int i=1; i<N; i++) {
        res += sum * A[i];
        res %= mod;
        sum += A[i];
        sum %= mod;
    }
    cout << res << endl;
}