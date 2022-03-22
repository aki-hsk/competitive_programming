#include<iostream>
#include<map>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;

const long long M = 1e12;
int main() {
    long long n;
    cin >> n;
    mint ans = 0;

    for(long long x=1; x*x<=n; x++) {
        ans += (n/x-x)/2 + 1;
    }
    cout << ans.val() << endl;
    return 0;
}