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

int k;
string s, t;
map<int, int> mp;

bool win(int i, int j) {
    string a = s.substr(0, 4) + char(i+'0');
    string b = t.substr(0, 4) + char(j+'0');
    map<int, int> mp1, mp2;
    for(int n=1; n<=9; n++) {
        mp1[n] = 0;
        mp2[n] = 0;
    }
    rep(i, 5) {
        mp1[a[i]-'0']++;
        mp2[b[i]-'0']++;
    }
    int score1 = 0, score2 = 0;
    for(auto m1:mp1) {
        score1 += m1.first * pow(10, m1.second);
    }
    for(auto m2:mp2) score2 += m2.first * pow(10, m2.second);
    return score1 > score2;
}

double probability(int i, int j) {
    map<int, int> mpx = mp;
    if(mpx[i] == 0 || mpx[j] == 0) {
        return 0;
    }
    double p1 = (double)mpx[i]/(9.0*k-8);
    mpx[i]--;
    if(mpx[j] == 0) return 0;
    double p2 = (double)mpx[j]/(9.0*k-9);
    return p1 * p2;
}

int main() {
    cin >> k >> s >> t;
    for(int i=1; i<=9; i++) mp[i] = k;
    for(int i=0; i<4; i++) {
        mp[s[i]-'0']--;
        mp[t[i]-'0']--;
    }

    double ans = 0;
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            if(win(i, j)) {
                ans += probability(i, j);
            }
        }
    }
    printf("%.20f\n", ans);
}