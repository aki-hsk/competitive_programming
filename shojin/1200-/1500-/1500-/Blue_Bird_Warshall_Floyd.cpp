#include<iostream>
#include<vector>
using namespace std;
const long long INF = 1LL<<60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for(int k=1; k<n; k++) {
        for(int i=1; i<n; i++) {
            for(int j=1; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    long long ans = INF;
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(dist[0][i] == INF || dist[0][j] == INF) continue;
            long long res = dist[0][i] + dist[i][j] + dist[j][0];
            ans = min(ans, res);
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}