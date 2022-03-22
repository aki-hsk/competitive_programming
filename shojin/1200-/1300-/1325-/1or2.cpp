#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct UnionFind {
    vector<int> par, siz; // par: 各頂点の親頂点の番号, siz: 各頂点の属する根付き木の頂点数
    UnionFind(int n) : par(n, -1), siz(n, 1) {} // 初期化
    int root(int x) {
        if(par[x] == -1) return x; // xが根の場合はxを返す
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y); // x,yをそれぞれ根まで移動
        if(x == y) return false;  // 既に同じグループの時は何もしない
        if(siz[x] < siz[y]) swap(x, y); // union by size(y側のサイズが小さくなるようにする)
        par[y] = x; // yをxの子とする
        siz[x] += siz[y];
        return true;
    }
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.unite(x, y);
    }
    set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(uf.root(i));
    }
    cout << st.size() << endl;
}