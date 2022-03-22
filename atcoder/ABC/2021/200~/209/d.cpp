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

int n, q;
vector<vector<int>> g;


int main() {
    cin >> n >> q;
    g.resize(n);
    rep(i, n-1) {
        int  a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, 0);
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto nv:g[v]) {
            if(dist[nv] != 0) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    rep(i, q) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        if((max(dist[c], dist[d])-min(dist[c], dist[d])) % 2 == 0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}