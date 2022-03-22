#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll dp[55][5000];
const int GETA = 2500;


int main(){
    int N, A;
    cin >> N >> A;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X[i], X[i] -= A;

    memset(dp, 0, sizeof(dp));
    dp[0][GETA] = 1;

    // 総和が0のときを s=2500としている。
    for(int i=0; i<N; i++) {
        for(int s=0; s+X[i]<=5000; s++) {
            if(dp[i][s] == 0) continue;
            dp[i+1][s] += dp[i][s];
            dp[i+1][s+X[i]] += dp[i][s];
        }
    }

    //何も選ばないを除く
    cout << dp[N][GETA] - 1 << endl;
}