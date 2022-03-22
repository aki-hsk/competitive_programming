#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    // N:マスの数, M:青色のマスの数
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M+1);
    rep(i, M) cin >> A[i];
    A[M] = N+1;
    sort(all(A));

    ll before = 0;
    ll div = N;
    ll ans = 0;
    rep(i, M+1) {
        // 連続していないとき
        if(A[i]-before > 1) {
            div = min(div, A[i]-before -1);
        }
        before = A[i];
    }
    rep(i, M+1) {
        if(A[i]-before > 1) {
            ans += (A[i] - before - 1 + div -1)/div;
        }
        before = A[i];
    }
    cout << ans << endl;
}