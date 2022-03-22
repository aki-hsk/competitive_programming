#include<iostream>
#include<vector>
#include<map>
#include<atcoder/all>
#include<numeric>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

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

mint permutation(int x) {
    mint res = 1;
    while(x != 0) {
        res *= x;
        x--;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    map<pair<int, int>, bool> ngx, ngy;
    for(int y1=0; y1<n; y1++) {
        for(int y2=y1+1; y2<n; y2++) {
            for(int j=0; j<n; j++) {
                if(a[y1][j] + a[y2][j] > k) {
                    ngy[{y1, y2}] = true;
                    break;
                }
            }
        }
    }
    for(int x1=0; x1<n; x1++) {
        for(int x2=x1+1; x2<n; x2++) {
            for(int i=0; i<n; i++) {
                if(a[i][x1] + a[i][x2] > k) {
                    ngx[{x1, x2}] = true;
                    break;
                }
            }
        }
    }

    UnionFind ufx(n), ufy(n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(ngx[{i, j}]) continue;
            ufx.unite(i, j);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(ngy[{i, j}]) continue;
            ufy.unite(i, j);
        }
    }
    map<int, bool> used;
    mint ans = 1;
    for(int i=0; i<n; i++) {
        if(used[ufx.root(i)]) continue;
        ans *= permutation(ufx.size(i));
        used[ufx.root(i)] = true;
    }
    used.clear();
    for(int i=0; i<n; i++) {
        if(used[ufy.root(i)]) continue;
        ans *= permutation(ufy.size(i));
        used[ufy.root(i)] = true;
    }
    cout << ans.val() << endl;
    return 0;
}