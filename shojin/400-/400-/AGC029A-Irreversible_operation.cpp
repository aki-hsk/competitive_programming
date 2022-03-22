#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll n=s.size(), m = 0, ms = 0, mg = 0;

    // 移動前の黒石の位置の和と黒石の個数
    rep(i,n) {
        if(s[i]=='B'){
            m++;
            ms+=i;
        }
    }

    // 移動後の黒石の位置の和
    for(int i=n-m;i<n;i++){
        mg += i;
    }

    cout << mg-ms << endl;
    return 0;
}
