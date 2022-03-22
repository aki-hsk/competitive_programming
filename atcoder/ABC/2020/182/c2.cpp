#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;
    int total_mod = 0;
    int d[3] = {};
    int len = 0;

    while(N) {
        int a = (N % 10) % 3;
        total_mod += a;
        total_mod %= 3;
        d[a]++;
        N /= 10;
        len++;
    }

    ll ans;
    if(total_mod == 0) {
        ans = 0;
    }
    else if(total_mod == 1) {
        if(d[1] >= 1 && len > 1) ans = 1;
        else if(d[2] >= 2 && len > 2) ans = 2;
        else ans = -1;
    }
    else if(total_mod == 2) {
        if(d[2] >= 1 && len > 1) ans = 1;
        else if(d[1] >= 2 && len > 2) ans = 2;
        else ans = -1;
    }

    cout << ans << endl;
}