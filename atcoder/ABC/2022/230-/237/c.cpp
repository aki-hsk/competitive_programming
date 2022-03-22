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

bool kaibun(string s) {
    int n = s.size();
    bool ok = true;
    rep(i, n/2) {
        if(s[i] != s[n-1-i]) ok = false;
    }
    return ok;
}
int main() {
    string s;
    cin >> s;

    int left = 0;
    while(left < s.size() && s[left] == 'a') {
        left++;
    }
    reverse(all(s));

    int right = 0;
    while(right < s.size() && s[right] == 'a') {
        right++;
    }
    rep(i, right - left) {
        s.push_back('a');
    }
    if(kaibun(s)) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}