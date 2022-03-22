#include<iostream>
using namespace std;
const long long mod = 1000000007;

int main() {
    long long n, k;
    cin >> n >> k;

    long long ans = 0;
    for(long long i=k; i<=n+1; i++) {
        long long x = i*(i-1)/2;
        long long y = i * (2*n - i + 1) / 2;
        ans += y-x+1;
        ans %= mod;
    }
    cout << ans << endl;
}