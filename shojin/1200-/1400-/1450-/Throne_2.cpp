#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

// {g, x, y} = ax + by = g
tuple<long long, long long, long long> extgcd(long long a, long long b) {
    if(b == 0) return {a, 1, 0};
    long long g, x, y;
    tie(g, x, y) = extgcd(b, a%b);
    return {g, y, x-a/b*y};
}

void solve() {
    int n, s, k;
    cin >> n >> s >> k;
    long long g, x, y;
    tie(g, x, y) = extgcd(k, n);
    if(s % g != 0) {
        cout << -1 << endl;
        return;
    }
    n /= g;
    s /= g;
    k /= g;
    long long ans = ((x * -s)%n+n)%n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        solve();
    }
    return 0;
}