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

int n;
vector<int> rec(int n) {
    if(n == 1) {
        vector<int> a = {1};
        return a;
    }
    vector<int> a = rec(n-1);
    vector<int> b = rec(n-1);
    a.push_back(n);
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

int main() {
    cin >> n;
    vector<int> ans = rec(n);
    int m = ans.size();
    for(int i=0; i<m; i++) {
        cout << ans[i] << (i == m-1 ? "\n" : " ");
    }
}