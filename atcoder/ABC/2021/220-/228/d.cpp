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
    const int N = 1048576;
    vector<ll> a(N, -1), next(N);
    rep(i, N) next[i] = (i+1) % N;
    rep(qi, q) {
        ll t, x;
        cin >> t >> x;
        if(t == 1) {
            ll x2 = x % N;
            ll p = x2;
            vector<int> A;
            while(a[x2] != -1) {
                A.push_back(x2);
                x2 = next[x2];
            }
            a[x2] = x;
            if(x2 != p) for(auto y:A) next[y] = x2;
        }
        else cout << a[x%N] << endl;
    }
}