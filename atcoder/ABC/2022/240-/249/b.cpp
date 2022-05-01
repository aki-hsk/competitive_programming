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

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, s.size()) {
      mp[s[i]]++;
    }
    bool ok0 = true;
    for(auto m:mp) {
      if(m.second > 1) ok0 = false;
    }

    bool ok1 = false, ok2 = false;
    rep(i, s.size()) {
      if(islower(s[i])) ok1 = true;
      if(isupper(s[i])) ok2 = true;
    }

    if(ok0 && ok1 && ok2) cout << "Yes" << endl;
    else cout << "No" << endl;
}