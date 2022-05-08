#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int h, w, q;
int to_num(int y, int x) {
  return y * w + x;
}

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n):par(n, -1), siz(n, 1) {}
  int root(int x) {
    if(par[x] == -1) return x;
    return par[x] = root(par[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
  bool issame(int x, int y) { return root(x) == root(y); }
};

int main() {
  cin >> h >> w >> q;
  UnionFind uf(h*w);
  map<int, bool> mp;

  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int r, c;
      cin >> r >> c;
      r--; c--;
      int now = to_num(r, c);
      mp[now] = true;
      for(int k=0; k<4; k++) {
        int ny = r + dy[k];
        int nx = c + dx[k];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        int next = to_num(ny, nx);
        if(mp.find(next) != mp.end()) uf.unite(now, next);
      }
    }
    else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--; ca--; rb--; cb--;
      int n1 = to_num(ra, ca);
      int n2 = to_num(rb, cb);
      if(uf.issame(n1, n2) && mp.find(n1) != mp.end() && mp.find(n2) != mp.end()) {
        printf("Yes\n");
      }
      else printf("No\n");
    }
  }
}
