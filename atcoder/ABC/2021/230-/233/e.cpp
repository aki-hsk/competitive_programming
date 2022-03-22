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

const int M = 500005;
int main() {
    string s;
    cin >> s;
    vector<ll> a(M);
    ll sum = 0;

    int n = s.size();
    for(int i=n-1; i>=0; i--) {
        ll m = s[n-1-i]-'0';
        a[i] += m + sum;
        sum += m;
    }

    vector<ll> ans(M);
    for(int i=0; i<M; i++) {
        ans[i] = a[i] % 10;
        int cnt = 0;
        while(a[i]) {
            if(cnt) a[i+cnt] += a[i] % 10;
            a[i] /= 10;
            cnt++;
        }
    }

    bool flg = false;
    for(int i=M-1; i>=0; i--) {
        if(ans[i] != 0) flg = true;
        if(flg) {
            cout << ans[i];
        }
    }
    cout << endl;
}