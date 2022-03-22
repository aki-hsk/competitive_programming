#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int SINF = 1LL << 29;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> dp(300, SINF);
    vector<int> ng(300, 0);
    rep(i, 3) {
        int a;
        cin >> a;
        ng[a]++;
    }
    dp[N] = 0;

    for(int i=N; i>=0; i--) {
        for(int j=1; j<=3; j++) {
            if(i-j >= 0) {
                if(ng[i-j]) continue;
                chmin(dp[i-j], dp[i] + 1);
            }
        }
    }

    if(dp[0] > 100 || ng[N]) cout << "NO" << endl;
    else cout << "YES" << endl;
}
