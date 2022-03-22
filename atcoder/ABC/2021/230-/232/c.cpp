#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(m);
    rep(i, m) {
        cin >> vp[i].first >> vp[i].second;
        vp[i].first--;
        vp[i].second--;
    }
    sort(all(vp));

    vector<pair<int, int>> vp2(m);
    rep(i, m) {
        cin >> vp2[i].first >> vp2[i].second;
        vp2[i].first--;
        vp2[i].second--;
    }

    vector<int> v(n);
    rep(i, n) v[i] = i;

    do {
        map<int, int> mp;
        rep(i, n) mp[i] = v[i];
        vector<pair<int, int>> vp3(m);
        rep(i, m) {
            vp3[i].first = mp[vp2[i].first];
            vp3[i].second = mp[vp2[i].second];
            if(vp3[i].first > vp3[i].second) swap(vp3[i].first, vp3[i].second);
        }

        bool ok = true;
        sort(all(vp3));
        rep(i, m) {
            if(vp[i].first != vp3[i].first) ok = false;
            if(vp[i].second != vp3[i].second) ok = false;
        }
        if(ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << "No" << endl;
    return 0;
}