#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

const int mod = 1000000007;

struct mint {
    long long x;
    mint(long long x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    // t乗を求める
    mint pow(long long t) const {
        if (!t) return 1; // tが0なら1を返す
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

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
    int n, a, b;
    cin >> n >> a >> b;
    mint ans = mint(2).pow(n);
    ans -= 1;
    ans -= choose(n, a);
    ans -= choose(n, b);
    cout << ans << endl;
    return 0;
}