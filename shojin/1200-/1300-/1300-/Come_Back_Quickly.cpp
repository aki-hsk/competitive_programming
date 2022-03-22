#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// ダイクストラ説明
// https://www.youtube.com/watch?v=X1AsMlJdiok

// 問題の説明
// https://www.youtube.com/watch?v=iEfDi7wagfE

struct E {
    int to, co;
    E(int to=0, int co=0): to(to), co(co) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<E>> g(n);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }

    const int INF = 1001001001;
    for(int sv=0; sv<n; sv++) {
        // 距離を記憶する
        vector<int> dist(n, INF);
        // priority_queue 昇順にする
        // priority_queue<入れる型, データ型, 比較関数>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        // pushという関数を使って(v, d)を引数にしている
        // 距離の更新をする関数
        auto push = [&](int v, int d) {
            // dist[v]の方が小さいなら何もしない
            if(dist[v] <= d) return;
            // 更新できるなら更新してqueueに入れる
            dist[v] = d;
            q.emplace(d, v);
        };

        // 今回は開始位置から一つ動いたところ
        for(auto&& e:g[sv]) push(e.to, e.co);
        while(!q.empty()) {
            auto[d, v] = q.top(); q.pop();
            if(dist[v] != d) continue;
            for(auto && e:g[v]) {
                push(e.to, d+e.co);
            }
        }

        int ans = dist[sv];
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}