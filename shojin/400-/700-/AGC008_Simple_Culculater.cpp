#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll x, y;
    cin >> x >> y;
    ll res = INF;
    // chminでは大きい方から小さい方を引く
    if(x <= y) chmin(res, y-x);         // 反転なし
    // y-(-x)
    if(-x <= y) chmin(res, y+x+1);      // 始めに反転
    // -y-(x)
    if(x <= -y) chmin(res, -y-x+1);     // あとで反転
    // -y-(-x)
    if(-x <= -y) chmin(res, -y+x+2);    // 始めとあとで反転
    cout << res << endl;
}