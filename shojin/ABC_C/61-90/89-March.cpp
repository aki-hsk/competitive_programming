#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    //頻度配列の型に注意
    // int -> long long
    vector<ll> MARCH(5, 0);
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        if(s[0] == 'M') MARCH[0]++;
        if(s[0] == 'A') MARCH[1]++;
        if(s[0] == 'R') MARCH[2]++;
        if(s[0] == 'C') MARCH[3]++;
        if(s[0] == 'H') MARCH[4]++;
    }

    ll ans = 0;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                ans += MARCH[i] * MARCH[j] * MARCH[k];
            }
        }
    }
    cout << ans << endl;
}