#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    vector<ll> SA(N+1, 0), SB(M+1, 0); // 累積和
    rep(i, N) cin >> A[i], SA[i+1] = SA[i] + A[i];
    rep(i, M) cin >> B[i], SB[i+1] = SB[i] + B[i];

    int result = 0;
    for(int x=0; x<=N; x++) {
        if(SA[x] > K) break;
        int y = upper_bound(SB.begin(), SB.end(), K-SA[x]) - SB.begin();
        --y;
        chmax(result, x + y);
    }
    cout << result << endl;
}