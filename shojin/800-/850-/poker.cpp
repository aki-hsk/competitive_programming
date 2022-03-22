#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

ll score(string s) {
    vector<ll> cnt(10);
    // cntに対して 0~9の連番を振る
    iota(cnt.begin(), cnt.end(), 0);
    for(char c:s) cnt[c-'0'] *= 10;
    // cntの和をとる
    return accumulate(cnt.begin(), cnt.end(), 0);
}

int main() {
    ll k;
    string s, t;
    cin >> k >> s >> t;
    vector<ll> cnt(10, k);
    for(char c:s + t) cnt[c - '0']--;
    ll win = 0;
    for(ll x = 1; x <= 9; x++) {
        for(ll y=1; y<=9; y++) {
            s.back() = '0' + x;
            t.back() = '0' + y;
            if(score(s) <= score(t)) continue;
            win += cnt[x] * (cnt[y] - (x == y));
        }
    }
    const ll rem = 9 * k - 8;
    cout << double(win) / rem / (rem - 1) << endl;
}