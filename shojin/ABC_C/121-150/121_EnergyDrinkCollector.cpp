#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const ll mod = 1000000000+7;

int main() {
    // N:店の数, M:解体ドリンクの本数
    ll N, M;
    cin >> N >> M;
    // A:1本Ai円, B:Bi本まで買える
    vector<pair<ll, ll>> v(N);
    rep(i, N) cin >> v[i].first >> v[i].second;
    sort(all(v));

    ll res = 0;
    for(int i = 0; i<N && M > 0; i++) {
        res += v[i].first * min(M, v[i].second);
        M -= min(M, v[i].second);
    }
    cout << res << endl;
}