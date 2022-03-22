#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // D:入力の数, G:目標点数
    ll D, G;
    cin >> D >> G;
    // p: 各問題の数, c:コンプリートボーナス
    vector<ll> p(D), c(D);
    rep(i, D) cin >> p[i] >> c[i];

    ll res = INF;
    for(int bit=0; bit<(1<<D); ++bit) {
        ll sum = 0; // 合計得点
        ll num = 0; // 解いた問題の数
        for(int i=0; i<D; i++) {
            if((bit>>i)&1) {
                sum += c[i] + p[i]*100*(i+1);
                num += p[i];
            }
        }
        if(sum >= G) res = min(res, num);   // 合計得点が超えていたら答えを最小値で更新
        else {
            // 得点の大きい問題から解いていく
            for(int i=D-1; i>=0; --i) {
                // コンプしていたら次の問題へ
                if((bit>>i)&1) continue;
                // 問題を解いていきsumが目標得点を超えたらbreak
                for(int j=0; j<p[i]; ++j) {
                    if(sum >= G) break;
                    sum += 100 * (i+1);
                    ++num;
                }
            }
            res = min(res, num);
        }
    }
    cout << res << endl;
}