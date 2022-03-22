#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    ll ans = INF;

    for(int x=0; x<=N; x++) {
        ll y;
        if((N-x)*E-H-B*x <0) y = 0;
        else y = ((double)(N-x)*E-H-B*x)/(D+E) + 1;
        chmin(ans, A*x+C*y);
    }
    cout << ans << endl;
    return 0;
}