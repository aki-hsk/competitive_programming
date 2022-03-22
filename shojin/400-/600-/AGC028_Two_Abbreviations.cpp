#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;

//最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll N, M; cin >> N >> M;
    string S, T; cin >> S >> T;
    ll g = gcd(N, M);
    ll d = lcm(N, M);

    bool flg = true;
    for(ll i=0; i<g; i++) {
        if(S[i*N/g] != T[M*i/g]) flg = false;
    }
    cout << (flg ? d : -1) << endl;
}