#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll x, y, A, B;
    cin >> x >> y >> A >> A;
    while(1) {
        if(y/A < x) break; //オーバフロー
        if(A * x >= y) break;
        if(A * x >= x + B) break;
        x *= a;
        ++ ans;
    }
    ans += (y-1-x)/b;
    cout << ans << endl;
    return 0;
}