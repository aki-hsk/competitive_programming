#include<iostream>
#include<vector>
using namespace std;
// 辺 uv がまったく使われない」ということは、uv 間の最短路が他にあることを意味する。

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, 1<<29));
    for(int i=0; i<n; i++) dist[i][i] = 0;
    vector<int> a(m), b(m), c(m);

    for(int i=0; i<m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<m; i++) {
        if(c[i] > dist[a[i]][b[i]]) ++ans;
    }
    cout << ans << endl;
    return 0;
}