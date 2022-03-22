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

bool tosa(ll x) {
    if(x < 100) return true;
    int div = x%100/10 - x%10;
    while(x/10) {
        if(x%100/10 - x%10 != div) return false;
        x /= 10;
    }
    return true;
}

int main() {
    ll x;
    cin >> x;
    if(tosa(x)) {
        cout << x << endl;
        return 0;
    }
    if(x <= 10000000) {
        for(ll i=x; i<=10000000; i++) {
            if(tosa(i)) {
                cout << i << endl;
                return 0;
            }
        }
    }

    ll ans = INF;
    vector<ll> v;
    v.push_back(1234567);
    v.push_back(2345678);
    v.push_back(3456789);
    v.push_back(9876543);
    v.push_back(8765432);
    v.push_back(7654321);
    v.push_back(6543210);
    v.push_back(12345678);
    v.push_back(23456789);
    v.push_back(98765432);
    v.push_back(87654321);
    v.push_back(76543210);
    v.push_back(123456789);
    v.push_back(987654321);
    v.push_back(876543210);
    v.push_back(9876543210);

    int cnt = to_string(x).size();
    for(int i=1; i<=9; i++) {
        ll sum = 0;
        rep(j, cnt) {
            sum *= 10;
            sum += i;
        }
        v.push_back(sum);
        sum = 0;
        rep(j, cnt+1) {
            sum *= 10;
            sum += i;
        }
        v.push_back(sum);
    }
    for(auto num:v) {
        if(x <= num) chmin(ans, num);
    }
    cout << ans << endl;


}