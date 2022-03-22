#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) v[i].push_back(-1);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        for(int j=0; j<a; j++) {
            // xが人の番号、yが正直者かどうか
            int x, y;
            cin >> x >> y;
            x--;
            v[i][x] = y;
        }
    }

    int ans = 0;
    // 誰が正直者か
    for(int bit=0; bit<(1<<n); bit++) {
        // d[i]: i人目が正直者かどうか
        vector<int> d(n, 0);
        for(int i=0; i<n; i++) {
            if(bit>>i&1) {
                d[i] = 1;
            }
        }
        bool flg = true;
        for(int i=0; i<n; i++) {
            // 正直者の中で整合をとる
            if(d[i]) {
                for(int j=0; j<n; j++) {
                    if(v[i][j] == -1) continue;
                    if(v[i][j] != d[j]) {
                        flg = false;
                        break;
                    }
                }
            }
        }
        if(flg) ans = max(ans, __builtin_popcount(bit));
    }
    cout << ans << endl;
}