#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    cout << SINF + 2 << endl;
    int n;
    double a, b;
    cin >> n >> a >> b;
    // SINF = 1LL << 60は 1e9より小さいので注意
    // INFで初期化する
    double m = INF, M = 0;
    double sum = 0;
    rep(i, n) {
        double v;
        cin >> v;
        chmin(m, v);
        chmax(M, v);
        sum += v;
    }
    double avg = sum / n;
    int div = M - m;

    if(div == 0) {
        cout << -1 << endl;
        return 0;
    }

    // Max-minを調整
    double p = b / div;
    avg *= p;
    // 平均点を調整
    double q = a - avg;
    printf("%.20f %.20f\n", p, q);
}