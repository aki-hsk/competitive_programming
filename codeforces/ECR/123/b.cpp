#include <bits/stdc++.h>
using namespace std;
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

void solve() {
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=1; i<=n; i++) dq.push_back(i);
    swap(dq[2], dq[3]);
    if(n == 3) {
        cout << "3 2 1" << endl;
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;
        return;
    }

    rep(i, n) {
        for(auto m:dq) cout << m << " ";
        cout << endl;
        int x = dq.front();
        dq.pop_front();
        dq.push_back(x);
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}