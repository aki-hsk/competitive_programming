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
    int q;
    cin >> q;
    multiset<ll> st;
    rep(i, 6) st.insert(-1);
    rep(i, 6) st.insert(INF);


    rep(qi, q) {
        int t;
        cin >> t;
        if(t == 1) {
            ll x;
            cin >> x;
            st.insert(x);
        }
        // x以下の要素のうち大きい方からkコメ
        else if(t == 2) {
            ll x, k;
            cin >> x >> k;
            k--;
            auto it = st.upper_bound(x);
            it--;
            rep(i, k) it--;
            if(*it == -1 || *it == INF) {
                cout << -1 << endl;
            }
            else cout << *it << endl;
        }
        // x以上の要素のうち小さい方からk個目
        else if(t == 3) {
            ll x, k;
            cin >> x >> k;
            k--;
            auto it = st.lower_bound(x);
            rep(i, k) it++;
            if(*it == -1 || *it == INF) {
                cout << -1 << endl;
            }
            else cout << *it << endl;
        }
    }
}
