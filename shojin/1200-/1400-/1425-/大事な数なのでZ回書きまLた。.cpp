#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    UnionFind(int n):par(n, -1) {}
    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        par[y] = x;
        return true;
    }
};

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    UnionFind uf(26);
    vector<bool> used(26, false);
    for(int i=0; i<n; i++) {
        if(isalpha(s[i]) && isalpha(t[i])) {
            int a = s[i]-'A';
            int b = t[i]-'A';
            if(used[uf.root(b)]) used[uf.root(a)] = true;
            if(used[uf.root(a)]) used[uf.root(b)] = true;
            uf.unite(a, b);
        }
        else if(isalpha(s[i])) {
            int a = s[i]-'A';
            used[uf.root(a)] = true;
        }
        else if(isalpha(t[i])) {
            int b = t[i]-'A';
            used[uf.root(b)] = true;
        }
    }
    long long ans = 1;
    for(int i=0; i<n; i++) {
        if(isdigit(s[i]) || isdigit(t[i])) continue;
        int a = s[i]-'A';
        int b = t[i]-'A';
        if(!used[uf.root(a)]) {
            if(i == 0) ans *= 9;
            else ans *= 10;
            used[uf.root(a)] = true;
        }
    }
    cout << ans << endl;
    return 0;
}