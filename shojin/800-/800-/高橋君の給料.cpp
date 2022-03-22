#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
const int SINF = 1LL<<29;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dfs(int x, vector<vector<int>> &v) {
    if(v[x].size() == 0) return 1;
    else if(v[x].size() == 1) {
        return dfs(v[x][0], v) * 2 + 1;
    }
    else {
        int M = 0, m = SINF;
        for(int i=0; i<v[x].size(); i++) {
            chmin(m, dfs(v[x][i], v));
            chmax(M, dfs(v[x][i], v));
        }
        return m + M + 1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    rep(i, n-1) {
        int a;
        cin >> a;
        a--;
        v[a].push_back(i+1);
    }
    cout << dfs(0, v) << endl;
}