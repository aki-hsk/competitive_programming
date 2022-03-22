#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;

    // B:各インデックスでの最大値
    // S:各インデックスまでの全てのtotal
    vector<ll> A(N), B, S;
    for(int i=0; i<N; i++) cin >> A[i];

    ll total = 0;
    ll sum = 0;
    ll max_sum = -INF;
    S.push_back(0);
    for(int i=0; i<N; i++) {
        sum += A[i];
        total += sum;
        chmax(max_sum, sum);
        B.push_back(max_sum);
        S.push_back(total);
    }

    ll ans = 0;
    for(int i=0; i<N; i++) {
        chmax(ans, S[i] + B[i]);
    }
    cout << ans << endl;
}