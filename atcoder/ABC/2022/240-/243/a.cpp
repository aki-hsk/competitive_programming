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
    int v;
    vector<int> a(3);
    cin >> v;
    rep(i, 3) cin >> a[i];

    int i = 0;
    while(v >= 0) {
        v -= a[i];
        if(v < 0) {
            if(i % 3 == 0) cout << "F" << endl;
            else if(i % 3 == 1) cout << "M" << endl;
            else cout << "T" << endl;
            return 0;
        }
        i = (i+1) % 3;
    }
}