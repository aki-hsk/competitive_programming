#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Union-Find
struct UnionFind
{
    // par: 各頂点の親頂点の番号, siz: 各頂点の属する根付き木の頂点数
    vector<int> par, siz;
    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
    // 根を求める
    int root(int x) {
        if(par[x] == -1) return x; // xが根の場合はxを返す
        else return par[x] = root(par[x]);
    }
    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    // xを含むグループとyを含むグループとを併合する
    bool unite(int x, int y) {
        // x,yをそれぞれ根まで移動
        x = root(x); y = root(y);
        // 既に同じグループの時は何もしない
        if(x == y) return false;
        // union by size(y側のサイズが小さくなるようにする)
        if(siz[x] < siz[y]) swap(x, y);
        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    UnionFind uf(200005);
    rep(i, n/2) {
        int x = a[i];
        int y = a[n-i-1];
        uf.unite(x, y);
    }

    ll ans = 0;
    map<int, bool> mp;
    rep(i, 200005) {
        if(i != uf.root(i)) continue;
        ans += uf.size(i) - 1;
    }
    cout << ans << endl;
}