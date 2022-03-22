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


ll solve(ll N, ll S, ll K) {
    ll X = N % K;
    ll Y = S % K;
    if(gcd(X, Y) == 1 && X != Y) return -1;
    if(X == Y) return (N - S) / K;

    ll ans = 0;
    int Z = K - N % K;
    while(X != Y) {
        Y = K - (N - S) % K;
        ans += (N-S)/K + 1;
        S = Y;
    }
    ans += (N-S)/K;
    return ans;
}

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        // N:椅子の数, S:時計回りにS個隣, K:K個時計回りの隣に座る
        ll N, S, K;
        cin >> N >> S >> K;
        cout << solve(N, S, K) << endl;
    }
}