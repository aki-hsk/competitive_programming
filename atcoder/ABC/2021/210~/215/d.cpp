#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX = 100000;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<int> ans;
    ans.push_back(1);

    vector<bool> num(100005, false);
    for(int i=2; i<=m; i++) {
        bool flg = true;
        if(num[i]) continue;
        for(int j=i; j<=MAX; j+=i) {
            if(mp[j]) flg = false;
        }
        if(!flg) {
            for(int j=i; j<=MAX; j+=i) {
                num[j] = true;
            }
        }
        if(flg) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto a:ans) cout << a << endl;
}