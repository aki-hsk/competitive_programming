#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int a[12][12];

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    int ans = 1001001001;

    //input
    for(int i=0; i<n; i++) {
        cin >> c[i];
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for(int s=0; s < 1<<n; s++) { //n=12の時 0 ~ 4095まで 2のn乗通り
        int cost = 0;
        vector<int> d(m);
        for(int i=0; i<n; i++) {
            if(s>>i&1) { //sのibit目が立っている時
                cost += c[i];
                for(int j=0; j<m; j++) d[j] += a[i][j];
            }
        }
        bool ok = true;
        for(int j=0; j<m; j++) if (d[j]<x) ok=false;
        if(ok) ans = min(ans, cost);
    }
    if(ans == 1001001001) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}