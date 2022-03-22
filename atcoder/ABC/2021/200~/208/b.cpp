#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll factorialMethod(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main() {
    ll p;
    cin >> p;
    vector<int> v(10);
    rep(i, 10) {
        v[i] = factorialMethod(i+1);
    }
    sort(rall(v));

    int cnt = 0;
    while(p) {
        rep(i, 10) {
            if(v[i] <= p) {
                p -= v[i];
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}