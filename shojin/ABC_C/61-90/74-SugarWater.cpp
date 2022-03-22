#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    //A: 水100A, B: 水100B
    //C: 砂糖C, D: 砂糖D
    //E: 水100gあたりに溶ける砂糖の量
    //F: ビーカーに入れられる物質の質量(水+砂糖)
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    set<ll> S, W;

    //水
    for(int i=0; i<=F; i++) {
        for(int j=0; j<=F; j++) {
            ll x = 100 * i * A + 100 * j * B;
            if(x <= F) {
                W.insert(x);
            }
        }
    }

    //砂糖
    for(int i=0; i<=F; i++) {
        for(int j=0; j<=F; j++) {
            ll y = i * C + j * D;
            if(y <= F) {
                S.insert(y);
            }
        }
    }

    //全列挙して配列に入れた、水と砂糖から最大濃度の砂糖水を作る
    double max_concentration = -100;
    ll amount_of_beaker = 0;
    ll amount_of_suger = 0;
    for(auto w:W) {
        for(auto s:S) {
            ll sum = w + s;
            if(sum > F) continue;
            double concentration = ((double)(100 * s) / (sum));
            if(concentration > max_concentration && (((double)E / 100) >= ((double)s / w))) {
                amount_of_beaker = sum;
                amount_of_suger = s;
                max_concentration = concentration;
            }
        }
    }
    //出力: 砂糖水の質量, 砂糖の質量
    cout << amount_of_beaker << " "<< amount_of_suger << endl;
}