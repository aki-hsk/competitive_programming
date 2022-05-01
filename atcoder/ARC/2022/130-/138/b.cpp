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
bool solve(deque<int> d) {
    bool flip = false;
    while(!d.empty()) {
        if(!flip) {
            if(d.back() == 0) d.pop_back();
            else if(d.back() == 1 && d.front() == 0) {
                d.pop_front();
                flip = !flip;
            }
            else return false;
        }
        if(flip) {
            if(d.back() == 1) d.pop_back();
            else if(d.back() == 0 && d.front() == 1) {
                d.pop_front();
                flip = !flip;
            }
            else return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    deque<int> d;
    rep(i, n) {
        int m;
        cin >> m;
        d.push_back(m);
    }

    if(solve(d)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}