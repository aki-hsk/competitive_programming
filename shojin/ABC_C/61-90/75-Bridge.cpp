#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, M;
bool graph[60][60];
bool vis[60];

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(int i=0; i<N; i++) {
        if(graph[x][i]) {
            dfs(i);
        }
    }
}

int main(){
    // N:頂点の数, M:辺の数
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }
    for(int i=0; i<N; i++) vis[i] = false;

    // 訪れることができる場所を調べる
    dfs(0);

    bool connected = true;
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            connected = false;
        }
    }
}