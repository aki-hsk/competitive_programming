#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int t[10][10];
int n, k;

bool dfs(int x, int num) {
    if(num == n) {
        if(x == 0) return true;
        else return false;
    }
    rep(i, k) {
        if(dfs(x ^ t[num][i], num + 1)) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    rep(i, n) rep(j, k) cin >> t[i][j];
    cout << (dfs(0, 0) ? "Found" : "Nothing") << endl;
}