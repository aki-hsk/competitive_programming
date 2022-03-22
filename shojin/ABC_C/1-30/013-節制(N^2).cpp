#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
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

int main() {
    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;

    ll ans = INF;
    for(int i=0; i<=N; i++) {
        for(int j=0; i + j<=N; j++) {
            if(H + B * i + D * j - (N - i - j) * E > 0) {
                chmin(ans, i * A + j * C);
            }
        }
    }
    cout << ans << endl;
}