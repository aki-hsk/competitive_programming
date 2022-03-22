#include<iostream>
#include<vector>
using namespace std;

int r[15][15];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) r[i][i] = 1;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        r[a][b] = 1;
        r[b][a] = 1;
    }

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++) {
        vector<int> v;
        for(int i=0; i<n; i++) {
            if(bit>>i&1) v.push_back(i);
        }
        bool flg = true;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<v.size(); j++) {
                if(!r[v[i]][v[j]]) {
                    flg = false;
                    break;
                }
            }
        }
        if(flg) {
            ans = max(ans, __builtin_popcount(bit));
        }
    }
    cout << ans << endl;
}