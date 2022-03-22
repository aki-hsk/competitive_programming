#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF = 1e18;
using P = pair<long long, int>;

// ダイクストラ

struct Edge
{
    int to, t, k;
    // メンバ初期化子リスト
    Edge(int to, int t, int k): to(to), t(t), k(k) {}
};


int main() {
    // n:都市の数, m:鉄道の数
    // x: 出発点, y:終点
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<Edge>> g(n);
    for(int i=0; i<m; i++) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        --a; --b;
        g[a].emplace_back(b, t, k);
        g[b].emplace_back(a, t, k);
    }

    vector<long long> dist(n, INF);

    // priority_queue 昇順にする
    // priority_queue<入れる型, データ型, 比較関数>

    // q<仮の最短距離, 頂点> が最小に並ぶ
    priority_queue<P, vector<P>, greater<P>> q;

    // pushという関数で(v, d)を引数にしている
    // 距離の更新をする関数
    auto push = [&](int v, long long d) {
        // dist[v]の方が小さいなら何もしない
        if(dist[v] <= d) return;
        // 更新できるなら更新してqueueに入れる
        dist[v] = d;
        q.emplace(d, v);
    };

    // 始点に値を入れる
    push(x, 0);
    while(!q.empty()) {
        // long long xとlong long vという変数か入ってque.top()の値が格納される
        // x:距離, v:頂点
        // この時点でpopされたqの地点は確定されている
        auto[d, v] = q.top(); q.pop();
        // 距離の情報が最新で無い場合は調べても無駄なのでcontinue
        if(dist[v] != d) continue;

        // 確定された地点から行ける場所の最短距離を更新する
        for(Edge &e:g[v]) {
            // 切り上げ
            // nx:次の駅までにかかる時間
            long long nx = (d+e.k-1)/e.k*e.k + e.t;
            push(e.to, nx);
        }
    }
    long long ans = dist[y];
    if(ans == INF) ans = -1;
    cout << ans << endl;
}