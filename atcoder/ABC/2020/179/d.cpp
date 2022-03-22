#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll mod = 998244353;

int main(){
    int N, K;
    cin >> N >> K;
    set<int> L, R;
    vector<int> V;

    for(int i=0; i<K; i++) {
        int l, r;
        cin >> l >> r;
        for(int j=l; j<=r; j++) {
            V.push_back(j);
        }
    }

    //dpで出すよ
    vector<ll> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    int M = V.size();
    sort(V.begin(), V.end());

    for(int i=2; i<=N; i++) {
        for(int j=0; j<M; j++) {
            if(i - V[j] < 1) break;
            else if(i - V[j] >= 1) {
                dp[i] += (dp[i-V[j]]);
                dp[i] %= mod;
            }
        }
    }
    dp[N] %= mod;
    cout << dp[N] << endl;
}