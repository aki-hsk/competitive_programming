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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> v(26);
    rep(i, n) {
        v[s[i]-'a'].push_back(i);
    }

    ll right = INF;
    string ans = s;
    rep(i, n/2) {
        int x = s[i]-'a';
        rep(j, x) {
            while(v[j].size() > 0 && v[j].back() > right) {
                v[j].pop_back();
            }
            if(v[j].empty()) continue;
            if(v[j].back() < i) continue;
            right = v[j].back();
            v[j].pop_back();
            swap(ans[i], ans[right]);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}