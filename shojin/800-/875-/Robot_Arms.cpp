#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

// 区間スケジューリング問題

int main() {
    int n; cin >> n;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) {
        ll a, l;
        cin >> a >> l;
        vp[i] = make_pair(a-l, a+l);
    }

    // 区間を右端の小さい順にソート
    sort(vp.begin(), vp.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second;});

    int res = 0;
    // cur:=現在選んでいる区間のうち最もみぎにあるものの右端
    ll cur = -(1LL << 60);
    for(int i=0; i<n; i++ ) {
        if(cur > vp[i].first) continue;
        ++res;
        cur = vp[i].second;
    }
    cout << res << endl;
}