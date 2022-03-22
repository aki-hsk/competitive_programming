#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;
    ll n = N;
    int total = 0;
    while(n) {
        total += n % 10;
        n /= 10;
    }
    string s = to_string(N);
    int k = s.size();

    int ans = SINF;
    for(int bit=0; bit<(1<<k)-1; bit++) {
        int x = total;
        for(int i=0; i<k; i++) {
            if((bit>>i)&1) {
                x -= (s[i]-'0');
            }
        }
        if(x % 3 == 0) chmin(ans, __builtin_popcount(bit));
    }
    if(ans == SINF) ans = -1;
    cout << ans << endl;
}