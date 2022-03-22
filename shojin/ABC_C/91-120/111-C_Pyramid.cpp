#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }

    //[0, 100]に座標があるのでMAXを定義すると楽
    const int MAX = 100;

    for(int posY = 0; posY <= MAX; posY++) {
        for(int posX = 0; posX <= MAX; posX++) {
            //頂上がどれくらいの高さであって欲しいか
            //-1はまだ分からない
            //-2はダメなとき
            int needH = -1;
            for(int i=0; i<N; i++) {
                if(h[i] > 0) {
                    //この頂点から見て、頂上がposY, posXのときに
                    //どれくらいの高さであって欲しいか
                    int tmp = h[i] + abs(posY - y[i]) + abs(posX - x[i]);
                    if(needH == -1) {
                        needH = tmp;
                    }
                    else {
                        if(needH != tmp) {
                            needH = -2;
                            break;
                        }
                    }
                }
            }
            //ダメであれば別の場所を探す
            if(needH == -2) continue;

            for(int i=0; i<N; i++) {
                //高さが0の場合に矛盾していないか調べる
                if(h[i] == 0) {
                    int dist = abs(posY - y[i]) + abs(posX - x[i]);
                    if(needH > dist) {
                        needH = -2;
                        break;
                    }
                }
            }
            if(needH == -2) continue;
            // 見つけられたら答えをそのまま返す
            cout << posX << " " << posY << " " << needH << endl;
            return 0;
        }
    }
}