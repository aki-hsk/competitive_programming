#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

// https://twitter.com/zaurus_yusya/status/1487426487964020737

mint choose(int n, int a) {
    mint x = 1, y = 1;
    // aの階乗
    for(int i=0; i<a; i++) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    long long x = accumulate(a.begin()+1, a.end(), 0LL);
    if(x > a[0]-k) {
        cout << 0 << endl;
        return 0;
    }

    mint ans = choose(a[0]-x-1, k-1);
    for(int i=1; i<n; i++) {
        ans *= choose(a[i]+k-1, k-1);
    }
    cout << ans.val() << endl;
    return 0;
}
