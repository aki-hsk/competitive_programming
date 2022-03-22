#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll m = stoll(s);

    ll min_cnt = INF;
    for(int bit=1; bit<(1<<s.size()); bit++) {
        ll cnt = 0;
        ll m = 0;
        for(int i=0; i<n; i++) {
            if(bit>>i&1) {
                m += (s[i]-'0');
                cnt++;
            }
        }
        if(m % 3 == 0) {
            chmin(min_cnt, n-cnt);
        }
    }
    if(min_cnt == INF) cout << -1 << endl;
    else cout << min_cnt << endl;
}