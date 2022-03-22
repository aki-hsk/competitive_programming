#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef pair<long long, int> Edge;
vector<ll> ds(200005, INF), ns(200005, 0);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(Edge(1, b));
        g[b].push_back(Edge(1, a));
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> que;
    que.push(Edge(0, 0));
    ds[0] = 0;
    ns[0] = 1;

    while(!que.empty()) {
        ll curd = que.top().first;
        int cur = que.top().second;
        que.pop();
        if(ds[cur] < curd) continue;
        for(auto e:g[cur]) {
            if (ds[e.second] > ds[cur] + e.first) {
                ds[e.second] = ds[cur] + e.first;
                ns[e.second] = ns[cur];
                que.push(Edge(ds[e.second], e.second));
            }
            else if (ds[e.second] == ds[cur] + e.first) {
                ns[e.second] += ns[cur];
                ns[e.second] %= mod;
            }
        }
    }
    cout << ns[n-1] << endl;
}