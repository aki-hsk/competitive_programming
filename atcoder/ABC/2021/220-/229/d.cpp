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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    long long right = s.size() + 1;
    long long left = 0;
    vector<ll> sum(n+1);
    ll num = 0;
    rep(i, n+1) {
        sum[i] = num;
        if(s[i] == 'X') num++;
    }

    while(right - left > 1) {
        ll mid = (right + left) / 2;
        // 連続する数をmid以上にできるか？
        bool flg = false;
        for(int i=0; i+mid<=n; i++) {
            if(sum[i+mid] - sum[i] + k >= mid) flg = true;
        }
        if(flg) left = mid;
        else right = mid;
    }
    cout << left << endl;
}