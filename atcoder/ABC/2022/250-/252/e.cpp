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

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}
  int root(int x) {
      if(par[x] == -1) return x;
      else return par[x] = root(par[x]);
  }
  bool issame(int x, int y) {
      return root(x) == root(y);
  }
  bool unite(int x, int y) {
      x = root(x); y = root(y);
      if(x == y) return false;
      if(siz[x] < siz[y]) swap(x, y);
      par[y] = x;
      siz[x] += siz[y];
      return true;
  }
  int size(int x) {
      return siz[root(x)];
  }
};

struct Edge {
  int from, to, num;
  long long cost;
  Edge(int from, int to, int num, long long cost):from(from), to(to), num(num), cost(cost) {};
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> e;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    e.push_back({a, b, i+1, c});
  }
  sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.cost < b.cost;});
  UnionFind uf(n);

  rep(i, m) {
    if(!uf.issame(e[i].from, e[i].to)) {
      uf.unite(e[i].from, e[i].to);
      cout << e[i].num << endl;
    }
  }
}