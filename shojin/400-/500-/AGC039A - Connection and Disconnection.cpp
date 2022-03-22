#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;

int main() {
    ll k;
    string s;
    cin >> s >> k;
    ll N = s.size();

    ll cnt = 1;
    ll d = 0;
    for(int i=0; i<N; i++) {
        if(s[i] == s[i+1]) cnt++;
        if(cnt == N) {
            cout << (N * k) / 2 << endl;
            return 0;
        }
        else if(i == N-1 || s[i] != s[i+1]) {
            d += cnt/2;
            cnt = 1;
        }
    }

    if(s[0] != s[N-1]) {
        cout << d * k << endl;
        return 0;
    }

    int pre_cnt = 1, suf_cnt = 1;
    rep(i, N-1) {
        if(s[i] == s[i+1]) pre_cnt++;
        else break;
    }
    rep(i, N-1) {
        if(s[N-1-i] == s[N-2-i]) suf_cnt++;
        else break;
    }

    ll join = ((pre_cnt + suf_cnt)/2) * (k - 1);
    ll edge = pre_cnt/2 + suf_cnt/2;
    cout <<  join + edge + (d - pre_cnt/2 - suf_cnt/2) * k << endl;

}
