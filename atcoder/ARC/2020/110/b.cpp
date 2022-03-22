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
    ll N;
    string t;
    cin >> N >> t;
    if(t == "1") {
        cout << (ll)2e10 << endl;
        return 0;
    }
    if(t == "0" || t == "11" || t == "10") {
        cout << (ll)1e10 << endl;
        return 0;
    }
    if(t == "01") {
        cout << (ll)1e10 - 1 << endl;
        return 0;
    }

    string s;
    ll x = (N/3)+3;

    for(int i=0; i<x; i++) {
        s += "110";
    }

    bool flg = false;
    int a;
    for(int i=0; i<s.size()-N+1; i++) {
        if(t == s.substr(i, N)) {
            flg = true;
            a = i;
            break;
        }
    }
    if(!flg) {
        cout << 0 << endl;
        return 0;
    }
    else cout << (ll)1e10 - (N+a) / 3 << endl;
}