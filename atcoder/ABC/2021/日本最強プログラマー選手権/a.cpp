#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    double a = y / x;
    for(int i=1; i<=100000000; i++) {
        if(i/z >= a) {
            cout << i-1 << endl;
            return 0;
        }
    }
}