#include<iostream>
#include<vector>
using namespace std;

// https://drken1215.hatenablog.com/entry/2019/02/16/075900

const long long INF = 1LL << 60;
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // sは始点
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for(int i=0; i<M; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back({b, -w});
    }

    // ベルマンフォード法

    // 負閉路を持つかどうか
    bool exist_negative_cycle = false;
    vector<long long> dist(N, INF);
    dist[0] = 0;
    for(int iter = 0; iter <= N*2; ++iter) {
        bool update = false;    // 更新が発生したかどうか
        for(int v = 0; v < N; v++) {
            // dist[v] = INFのときは頂点vからの緩和を行わない
            if(dist[v] == INF/2) continue;
            for(auto e:G[v]) {
                // 緩和更新を行い、更新されたらupdateをtrueにする
                if(chmin(dist[e.to], dist[v] + e.w)) {
                    if(e.to == N-1 && iter == N*2) exist_negative_cycle = true;
                }
            }
        }
    }

    if(exist_negative_cycle) cout << "inf" << endl;
    else cout << -dist[N-1] << endl;
}