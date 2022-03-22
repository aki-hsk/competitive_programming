#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // 洞窟がn個, 通路がm個
    // O(n+m)
    // beforeをメモっておくと良い
    // NOはありえない
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, SINF);
    vector<int> pre(n);
    dist[0] = 0;
    queue<int> que;
    que.push(0);

    while(que.size() != 0) {
        int x = que.front();
        que.pop();
        for(int i=0; i<g[x].size(); i++) {
            int next_cave = g[x][i];
            if(dist[next_cave] != SINF) continue;
            que.push(next_cave);
            pre[next_cave] = x;
            dist[next_cave] = dist[x]+1;
        }
    }

    cout << "Yes" << endl;
    rep(i, n) {
        if(i != 0) cout << pre[i] + 1 << endl;
    }
}