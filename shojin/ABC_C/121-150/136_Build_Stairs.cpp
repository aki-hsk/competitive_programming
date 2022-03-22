#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i, N) cin >> h[i];
    h[0]--;

    bool flg = true;
    for(int i=1; i<N; i++) {
        if(h[i]-h[i-1] >= 1) h[i]--;
        if(h[i] < h[i-1]) flg = false;
    }

    cout << (flg ? "Yes" : "No") << endl;
}
