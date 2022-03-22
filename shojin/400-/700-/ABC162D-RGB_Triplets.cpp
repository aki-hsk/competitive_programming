#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> v(3, 0);
    rep(i, n) {
        if(s[i] == 'R') v[0]++;
        else if(s[i] == 'G') v[1]++;
        else if(s[i] == 'B') v[2]++;
    }

    ll cnt = v[0] * v[1] * v[2];
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int k = j + (j-i);
            if(k < n) {
                if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) cnt--;
            }
        }
    }
    cout << cnt << endl;
}