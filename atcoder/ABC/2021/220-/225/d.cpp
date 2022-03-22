#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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


vector<int> ch;
vector<int> par;

int parent(int c) {
    if(par[c] != -1) return parent(par[c]);
    return c;
}

void output_child(int x, vector<int> &ans) {
    ans.push_back(x);
    if(ch[x] != -1) output_child(ch[x], ans);
}


int main() {
    int n, q;
    cin >> n >> q;
    ch.resize(n+1, -1);
    par.resize(n+1, -1);

    rep(i, q) {
        int m;
        cin >> m;
        if(m == 1) {
            int x, y;
            cin >> x >> y;
            ch[x] = y;
            par[y] = x;
        }
        else if(m == 2) {
            int x, y;
            cin >> x >> y;
            ch[x] = -1;
            par[y] = -1;
        }
        else {
            int x;
            cin >> x;
            int p = parent(x);
            vector<int> ans;
            output_child(p, ans);
            cout << ans.size() << " ";
            for(auto a:ans) cout << a << " ";
            cout << endl;
        }
    }
}