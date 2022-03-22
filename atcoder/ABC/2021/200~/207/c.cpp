#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> vp;
    rep(i, n) {
        double t, l, r;
        cin >> t >> l >> r;
        if(t == 2) r -= 0.1;
        if(t == 3) l += 0.1;
        if(t == 4) {
            r -= 0.1;
            l += 0.1;
        }
        vp.push_back(make_pair(l, r));
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(vp[j].first <= vp[i].second && vp[i].first <= vp[j].second){
                ans++;
            }
        }
    }
    cout << ans << endl;
}