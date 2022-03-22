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

// Send More Money

string str_to_num(string str, map<char,char> &mp) {
    string x;
    int n = str.size();
    rep(i, n) {
        x.push_back(mp[str[i]]);
    }
    return x;
}

int main() {
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    string t = s[0] + s[1] + s[2];
    sort(all(t));
    t.erase(unique(t.begin(), t.end()), t.end());
    if(t.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    do {
        map<char, char> mp;
        rep(i, t.size()) mp[t[i]] = v[i] + '0';
        vector<string> str(3);
        rep(i, 3) str[i] = str_to_num(s[i], mp);
        if(str[0][0] == '0' || str[1][0] == '0' || str[2][0] == '0') continue;
        vector<ll> num(3);
        rep(i, 3) num[i] = stoll(str[i]);
        if(num[0] + num[1] == num[2]) {
            rep(i, 3) cout << num[i] << endl;
            return 0;
        }
    } while(next_permutation(all(v)));

    cout << "UNSOLVABLE" << endl;
}

