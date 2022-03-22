#include<iostream>
#include<vector>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    int size(int x) { return siz[root(x)]; }
};

int h, w, q;
bool board[2005][2005];
int to_num(int y, int x) {
    return y * w + x;
}

int main() {
    cin >> h >> w >> q;
    UnionFind uf(h*w);
    for(int qi=0; qi<q; qi++) {
        int t;
        cin >> t;
        if(t == 1) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            board[r][c] = true;
            for(int k=0; k<4; k++) {
                int nr = r + dy[k];
                int nc = c + dx[k];
                if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if(board[nr][nc]) uf.unite(to_num(nr, nc), to_num(r, c));
            }
        }
        else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            y1--; x1--; y2--; x2--;
            if(uf.issame(to_num(y1, x1), to_num(y2, x2)) && board[y1][x1] && board[y2][x2]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }
}
