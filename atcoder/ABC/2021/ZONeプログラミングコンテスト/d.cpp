#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;

    deque<char> deq;
    bool rev = false;

    rep(i, s.size()) {
        if(s[i] == 'R') rev = !rev;
        else if(rev) deq.push_front(s[i]);
        else deq.push_back(s[i]);
    }
    string ans;
    for(auto tmp:deq) ans.push_back(tmp);
    if(rev) reverse(all(ans));
    string res = "";
    rep(i, ans.size()) {
        res.push_back(ans[i]);
        if(res.size() >= 2) {
            string a = res.substr(res.size()-2, 2);
            if(a[0] == a[1]) res.erase(res.size()-2, 2);
        }
    }
    cout << res << endl;
}