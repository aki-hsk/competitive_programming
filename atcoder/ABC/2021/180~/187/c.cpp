#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N) {
        string s = S[i];
        if(s[0] != '!' && mp[s] == 0) mp[s]++;
    }

    rep(i, N) {
        string s = S[i];
        if(s[0] == '!') {
            string t = s.substr(1);
            if(mp[t] == 1) mp[t]++;
        }
    }

    for(auto m:mp) {
        if(m.second > 1) {
            cout << m.first << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}