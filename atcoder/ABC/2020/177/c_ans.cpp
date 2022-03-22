#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int mod = 1000000007;
    ll sum = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    long ans = 0;
    for(int i=0; i<N; i++) {
        sum -= A[i];
        if(sum < 0) sum += mod;

        ans += A[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
}