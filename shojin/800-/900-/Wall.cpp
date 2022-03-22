#include<iostream>
#include<vector>
using namespace std;

// 最短経路問題
// Warshall Floyd: ワーシャルフロイド

// iからjへの直接の距離
int dist[10][10];

int main() {
    int h, w;
    cin >> h >> w;
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) cin >> dist[i][j];
    int wall[h][w];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) cin >> wall[i][j];

    for(int k=0; k<10; k++) {
        for(int i=0; i<10; i++) {
            for(int  j=0; j<10; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
        if(wall[i][j] == -1 || wall[i][j] == 1) continue;
        else ans += dist[wall[i][j]][1];
    }
    cout << ans << endl;
}