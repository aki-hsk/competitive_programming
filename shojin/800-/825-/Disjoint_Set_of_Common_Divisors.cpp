#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

//最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


// a,bの最大公約数の約数は公約数になる！！
int main() {
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> vp = prime_factorize(gcd(a, b));
    cout << vp.size() + 1 << endl;
}