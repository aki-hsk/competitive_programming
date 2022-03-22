#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N;
    cin >> N;
    ll F[N][10];
    ll P[N][11];

    //店Nが開いている時間帯
    for(int i=0; i<N; i++) for(int j=0; j<10; j++) cin >> F[i][j];
    //i:店N j:joisino共に開いている時間帯の個数
    for(int i=0; i<N; i++) for(int j=0; j<11; j++) cin >> P[i][j];　

    ll max_profit = -INF;

    for(int bit=1; bit<(1<<10); bit++) {
        ll profit = 0;
        // 店の数
        for(int j=0; j<N; j++) {
            int count = 0;
            // 時間帯
            for(int k=0; k<10; k++) {
                // 店kとjoisinoの店が両方営業している時間帯の個数
                if(((bit>>k)&1) && F[j][k]) count++;
            }
            profit += P[j][count];
        }
        chmax(max_profit, profit);
    }
    cout << max_profit << endl;
}