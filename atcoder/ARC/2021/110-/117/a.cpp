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
    int a, b;
    cin >> a >> b;
    vector<int> p(a), n(b);

    if(a >= b) {
        for(int i=0; i<a; i++) p[i] = i+1;
        for(int i=0; i<b-1; i++) n[i] = -(i+1);
        n[b-1] = -abs(a*(a+1)/2-b*(b-1)/2);
        rep(i, a) cout << p[i] << endl;
        rep(i, b) cout << n[i] << endl;
    }

    else {
        for(int i=0; i<b; i++) n[i] = -(i+1);
        for(int i=0; i<a-1; i++) p[i] = i+1;
        p[a-1] = abs(b*(b+1)/2-a*(a-1)/2);
        rep(i, a) cout << p[i] << endl;
        rep(i, b) cout << n[i] << endl;
    }
}