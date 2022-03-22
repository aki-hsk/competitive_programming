#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

const ll C = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> M(N+1);

    for(int i=2; i<=N; i++) {
        ll num = i;
        for(int j=2; j/2<=i; j++) {
            while(num % j == 0) {
                M[j]++;
                num /= j;
            }
            if(num <= 1) {
                break;
            }
        }
    }

    ll ans = 1;
    for(int i=0; i<N+1; i++) {
        ans *= M[i]+1;
        ans %= 1000000007;
    }
    cout << ans << endl;
}