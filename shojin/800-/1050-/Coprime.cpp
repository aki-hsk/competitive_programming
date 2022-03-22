#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 30;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// mapで管理すると間に合わないよ！！

int main() {
    int n;
    cin >> n;
    const int A = 1000005;
    map<int, int> mp;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    bool pairwise = true;
    if(n != mp.size()) pairwise = false;
    for(int i=2; i*i<A; i++) {
        int cnt = 0;
        for(int j=i; j<A; j+=i) {
            if(mp[j]) cnt += mp[j];
        }
        if(cnt > 1) {
            pairwise = false;
            break;
        }
    }

    int g = a[0];
    rep(i, n) g = __gcd(g, a[i]);
    if(pairwise) cout << "pairwise coprime" << endl;
    else if(g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}