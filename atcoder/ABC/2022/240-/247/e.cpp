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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> v;
    bool use_x = false, use_y = false;
    vector<int> b;
    rep(i, n) {
        if(a[i] < y || a[i] > x) {
            if(!b.empty() && use_x && use_y) {
                v.push_back(b);
            }
            b.clear();
            use_x = false;
            use_y = false;
        }
        else {
            b.push_back(a[i]);
            if(a[i] == x) use_x = true;
            if(a[i] == y) use_y = true;
        }
    }
    if(!b.empty() && use_x && use_y) v.push_back(b);

    ll sum = 0;
    for(auto a:v) {
        vector<int> va, vb;
        va.push_back(-1);
        vb.push_back(-1);
        ll m = a.size();
        for(int i=0; i<m; i++) {
            if(a[i] == x) va.push_back(i);
            if(a[i] == y) vb.push_back(i);
        }
        va.push_back(m);
        vb.push_back(m);
        sum += m * (m + 1) / 2;
        for(int i=1; i<va.size(); i++) {
            ll num = (va[i]-va[i-1]-1);
            cout << i << " " << num << " " << va[i] << " " << va[i-1] << endl;
            sum -= num * (num-1) / 2;
        }
        for(int i=1; i<vb.size(); i++) {
            ll num = (vb[i]-vb[i-1]-1);
            sum -= num * (num-1) / 2;
        }
    }
    cout << sum << endl;
}