#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void output(int s) {
    vector<int> a;
    int i=1;
    while(s) {
        if(s&1) a.push_back(i);
        ++i;
        // sをシフト
        s >>= 1;
    }
    cout << a.size();
    for(int x:a) cout << " " << x;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    n = min(n, 8);
    vector<int> st(200, 0);
    for(int bit=1; bit<(1<<n); bit++) {
        int x = 0;
        for(int i=0; i<n; i++) if(bit >> i&1) x = (x+a[i])%200;
        if(st[x] == 0) st[x] = bit;
        else {
            cout << "yes" << endl;
            output(bit);
            output(st[x]);
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}