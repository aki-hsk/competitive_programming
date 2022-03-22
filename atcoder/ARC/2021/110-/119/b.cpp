#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int s_1 = 0, s_0 = 0, t_1 = 0, t_0 = 0;
    rep(i, s.size()) {
        if(s[i] == '1') s_1++;
        if(s[i] == '0') s_0++;
        if(t[i] == '1') t_1++;
        if(t[i] == '0') t_0++;
    }

    if(s_1 != t_1 || s_0 != t_0) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    int i=0;
    while(i < n) {
        while(s[i] == t[i]) i++;
        int start = i;
        i++;
        while(i+1 < n && s[i] == s[i+1] && s[i] == t[i]) i++;
        if(i < n && s[i] != t[i]) {
            swap(s[start], s[i]);
            cnt++;
            cout << s << endl;
        }
    }
    cout << cnt << endl;
    int wrong = 0;
    rep(i, n) if(s[i] != t[i]) wrong++;
    cout << cnt + wrong << endl;
}