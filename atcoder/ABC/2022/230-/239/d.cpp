#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX = 100005;

// エラトステネスの篩
void sieve_of_eratosthenes(vector<bool> &prime) {
    prime[0] = prime[1] = false;
    for(int i=2; i*i<MAX; i++) {
        if(!prime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) {
            prime[j] = false;
        }
    }
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<bool> prime(MAX, true);
    sieve_of_eratosthenes(prime);

    for(ll i=a; i<=b; i++) {
        bool ok = true;
        for(int j=c; j<=d; j++) {
            if(prime[i+j]) ok = false;
        }
        if(ok) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}