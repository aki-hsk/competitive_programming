#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
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
    int n;
    cin >> n;
    map<ll, ll> mp;
    vector<ll> v(n+1, 0);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        mp[a]++;
        mp[a+b]--;
    }

    ll num = 0;
    ll before = 0;
    for(auto m:mp) {
        v[num] += (m.first - before);
        num += m.second;
        before = m.first;
    }

    for(int i=1; i<=n; i++) cout << v[i] << endl;
}