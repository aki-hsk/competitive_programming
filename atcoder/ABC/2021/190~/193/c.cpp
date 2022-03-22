#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll power(ll a, ll b) {
    ll res = 1;
    rep(i, b) {
        res *= a;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    int cnt = 0;
    set<ll> st;
    for(int a=2; a<=100000; a++) {
        for(int b=2; b<100; b++) {
            if(power(a, b) > n) break;
            st.insert(power(a, b));
        }
    }
    cout << n - st.size() << endl;
}