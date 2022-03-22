#include<iostream>
#include<vector>
using namespace std;

const int M = 1e5+5;
int main() {
    int n;
    cin >> n;
    vector<int> rate(M);
    // 0:グー, 1:チョキ, 2:パー
    vector<vector<int>> rh(M, vector<int>(3));
    vector<int> r(n), h(n);
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        r[i] = x;
        h[i] = y;
        rate[x]++;
        rh[x][y]++;
    }
    for(int i=0; i<M; i++) rate[i+1] += rate[i];

    for(int i=0; i<n; i++) {
        int win = rate[r[i]-1] + rh[r[i]][(h[i]+1)%3];
        int draw = rh[r[i]][h[i]] - 1;
        int lose = n-1-win-draw;
        printf("%d %d %d\n", win, lose, draw);
    }
    return 0;
}