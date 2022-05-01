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
    deque<pair<ll, ll>> d;

    rep(qi, q) {
        int t;
        cin >> t;
        if(t == 1) {
            ll x, c;
            cin >> x >> c;
            d.push_back({x, c});
        }
        else {
            ll c;
            cin >> c;
            ll sum = 0;
            for(auto &&p:d) {
                if(p.second < c) {
                    sum += p.first * p.second;
                    c -= p.second;
                    p.second = 0;
                }
                else {
                    p.second -= c;
                    sum += c * p.first;
                    break;
                }
            }
            printf("%lld\n", sum);
        }
        while(!d.empty() && d.front().second == 0) {
            d.pop_front();
        }
    }
}