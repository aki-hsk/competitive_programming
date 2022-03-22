#include<iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n;
    for(long long i=1; i<=n; i++) {
        if(i*i <= n) k = i;
        else break;
    }
    long long ans = 0;
    for(long long i=1; i<=k; i++) {
        // n/k=iとなるものの和
        ans += ((n/i)-(n/(i+1))) * i;
    }
    for(long long i=1; i<=n/(k+1); i++) {
        ans += (n/i);
    }
    cout << ans << endl;
    return 0;
}