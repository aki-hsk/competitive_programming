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
    deque<int> p;
    deque<int> a;
    rep(i, n) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    if(p.front() != n && p.back() != n) {
        cout << -1 << endl;
        return;
    }

    while(!p.empty()) {
        if(p.size() == 1) {
            a.push_back(p.front());
            p.pop_back();
            break;
        }

        int f = p.front();
        int b = p.back();
        if(f > b) {
            a.push_front(p.front());
            p.pop_front();
        }
        else {
            a.push_back(p.back());
            p.pop_back();
        }
    }
    for(auto x:a) cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}