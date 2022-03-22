#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

struct UnionFind {
    vector<int> par, siz, num;
    UnionFind(int n):par(n, -1), siz(n, 1), num(n, -1) {}
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
        if(get_num(y) != -1) num[x] = num[y];
        par[y] = x;
        return true;
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return siz[root(x)];
    }
    void set_num(int x, int m) {
        num[root(x)] = m;
    }
    int get_num(int x) {
        return num[root(x)];
    }
};

int main() {
    int n;
    cin >> n;
    UnionFind uf(26);
    string a, b;
    cin >> a >> b;

    rep(i, n) {
        if(a[i] == b[i]) continue;
        if(isupper(a[i]) && isupper(b[i])) {
            uf.unite(a[i]-'A', b[i]-'A');
        }
        else if(isupper(a[i])) {
            uf.set_num(a[i]-'A', b[i]-'0');
        }
        else if(isupper(b[i])) {
            uf.set_num(b[i]-'A', a[i]-'0');
        }
    }

    ll ans = 1;
    rep(i, n) {
        if(isupper(a[i]) && isupper(b[i])) {
            int x = a[i]-'A';
            if(uf.get_num(x) == -1) {
                ans *= (i == 0 ? 9 : 10);
                uf.set_num(x, 100);
            }
        }
    }
    cout << ans << endl;
    return 0;
}