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

int n, m;
vector<int> it, k;
vector<vector<int>> a;
map<int, int> mp;

void dfs(int x) {
    int i = it[x];
    if(i == k[x]) return;
    if(mp[a[x][i]]) {
        it[mp[a[x][i]]]++;
        it[x]++;
        dfs(x);
        dfs(mp[a[x][i]]);
    }
    mp[a[x][i]] = x;
    dfs(x+1);
}

int main() {
    // 2*n:ボールの個数 n種類
    // m:筒の本数
    cin >> n >> m;
    it.resize(m);
    a.resize(m);
    k.resize(m);
    rep(i, m) {
        int x;
        cin >> x;
        k[i] = x;
        rep(j, x) {
            int b;
            cin >> b;
            a[i].push_back(b);
        }
    }
    if(!dfs(0)) cout << "No" << endl;
    else cout << "Yes" << endl;
}