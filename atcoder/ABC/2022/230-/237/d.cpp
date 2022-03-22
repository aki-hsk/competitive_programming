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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> next(n+1, -1);
    vector<int> prev(n+1, -1);

    rep(i, n) {
        if(s[i] == 'L') {
            if(prev[i] != -1) next[prev[i]] = i+1;
            if(prev[i] != -1) prev[i+1] = prev[i];
            prev[i] = i+1;
            next[i+1] = i;
        }
        else if(s[i] == 'R') {
            if(next[i] != -1) prev[next[i]] = i+1;
            if(next[i] != -1) next[i+1] = next[i];
            next[i] = i+1;
            prev[i+1] = i;
        }
    }
    int st;
    rep(i, n+1) {
        if(prev[i] == -1) st = i;
    }
    cout << st << endl;
    while(next[st] != -1) {
        cout << next[st] << endl;
        st = next[st];
    }
}