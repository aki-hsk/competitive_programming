#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint998244353;
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
    long long n;
    cin >> n;
    int keta = to_string(n).size();
    mint ans = 0;
    mint x = 1;
    rep(i, keta-1) {
        mint a = x;
        mint b = x*10-1;
        mint m = (b-a+1);
        ans += m * (m+1) / 2;
        x *= 10;
    }
    mint a = x;
    mint b = n;
    mint m = (b-a+1);
    ans += m * (m+1) / 2;
    cout << ans.val() << endl;
    return 0;
}