#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(b.begin(), b.end());

    set<int> ans;
    for(int i=0; i<n; i++) {
        int x = a[0]^b[i];
        vector<int> c;
        rep(j, n) c.push_back(x^a[j]);
        sort(c.begin(), c.end());
        // vectorの一致
        // https://www.it-swarm-ja.com/ja/c%2B%2B/%27%27%E3%82%92%E4%BD%BF%E7%94%A8%E3%81%97%E3%81%A62%E3%81%A4%E3%81%AE%E3%83%99%E3%82%AF%E3%83%88%E3%83%AB%E3%82%92%E6%AF%94%E8%BC%83%E3%81%A7%E3%81%8D%E3%81%BE%E3%81%99%E3%81%8B%E3%80%82%E7%A7%81%E3%81%AF%E3%81%9D%E3%82%8C%E3%82%92%E8%A9%A6%E3%81%97%E3%81%A6%E3%81%BF%E3%81%BE%E3%81%97%E3%81%9F%E3%81%8C%E3%80%81%E3%81%86%E3%81%BE%E3%81%8F%E6%A9%9F%E8%83%BD%E3%81%97%E3%81%A6%E3%81%84%E3%82%8B%E3%82%88%E3%81%86%E3%81%A7%E3%81%99%E3%80%82%E3%81%97%E3%81%8B%E3%81%97%E3%80%81%E3%82%88%E3%82%8A%E8%A4%87%E9%9B%91%E3%81%AA%E7%8A%B6%E6%B3%81%E3%81%A7%E6%A9%9F%E8%83%BD%E3%81%99%E3%82%8B%E3%81%8B%E3%81%A9%E3%81%86%E3%81%8B%E3%81%AF%E3%82%8F%E3%81%8B%E3%82%8A%E3%81%BE%E3%81%9B%E3%82%93/1073697878/
        if(b == c) ans.insert(x);
    }
    cout << ans.size() << endl;
    for(auto aa:ans) cout << aa << endl;
}