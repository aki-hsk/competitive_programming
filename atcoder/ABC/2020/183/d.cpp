#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // N:人, W:毎分Wリットル
    ll N, W;
    cin >> N >> W;
    // S~TまでPリットル使いたい
    vector<ll> S(N), T(N), P(N);
    rep(i, N) {
        cin >> S[i] >> T[i] >> P[i];
    }


    vector<ll> value(200000, 0);
    for(int i=0; i<N; i++) {
        value[S[i]] += P[i];
        value[T[i]] -= P[i];
    }


    ll total = 0;
    ll v = 0;
    for(int i=0; i<11; i++) {
        cout << value[i];
        v += value[i];
        chmax(total, v);
    }

    if(total <= W) cout << "Yes" << endl;
    else cout << "No" << endl;
}