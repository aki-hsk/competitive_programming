#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 101010;
int imos[30][M];

int main() {
    int N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        c--;
        imos[c][a]++;
        imos[c][b+1]--;
    }

    for(int c=0; c<C; c++) for(int i=0; i<M; i++) {
        imos[c][i] += imos[c][i-1];
    }
    for(int c=0; c<C; c++) for(int i=0; i<M; i++) {
        if(imos[c][i]) imos[c][i] = 1;
    }

    int ans = 0;
    for(int i=0; i<M; i++) {
        int cnt = 0;
        for(int c=0; c<C; c++) cnt += imos[c][i];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}