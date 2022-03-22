#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

long long solve(long long m, long long s, long long a) {
    int b = m - s;
    // a * x ≡ b (mod m)
    long long g = gcd(gcd(a, b), m);
    a /= g;
    b /= g;
    m /= g;
    // a * x ≡ b (mod m)
    // mod mでの aの逆元が存在する条件は mと aとが互いに素であること
    // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-3-%E9%80%86%E5%85%83%E3%81%AE%E6%B1%82%E3%82%81%E6%96%B9%E3%81%AE%E6%A6%82%E8%A6%81
    if(gcd(a, m) > 1) return -1;
    long long y = inv_mod(a, m);
    return (b * y) % m;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, s, k;
        cin >> n >> s >> k;
        cout << solve(n, s, k) << endl;
    }
}