#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const long long INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int n = s.size() + 1;
    vector<int> v(n, 0);

    for(int i=0; i<n-1; i++) {
        if(s[i] == '<') {
            v[i+1] = max(v[i]+1, v[i+1]);
        }
    }
    for(int i=n-1; i>0; i--) {
        if(s[i-1] == '>') {
            v[i-1] = max(v[i]+1, v[i-1]);
        }
    }
    ll sum = 0;
    rep(i, n) sum += v[i];
    cout << sum << endl;
}
