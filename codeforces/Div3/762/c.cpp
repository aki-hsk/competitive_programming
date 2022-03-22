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

string add(string x, string y) {
    string sum;
    if(x.size() < y.size()) swap(x, y);
    reverse(all(x));
    reverse(all(y));
    rep(i, x.size()-y.size()) y.push_back('0');
    int i=0, j=0;
    while(i < x.size()) {
        int a = x[i]-'0';
        int b = y[j]-'0';
        i++;
        j++;
        sum = to_string(a + b) + sum;
    }
    return sum;
}


void solve() {
    string x, sum;
    cin >> x >> sum;
    int si = 0, xi = 0;
    int n = x.size();
    int m = sum.size();
    reverse(all(x));
    reverse(all(sum));
    string y;
    bool ok = true;
    while(si < m) {
        int a = sum[si]-'0';
        int b = 0;
        if(xi < n) b = x[xi]-'0';
        if(a < b && si < m-1) {
            si++;
            a += (sum[si]-'0') * 10;
        }
        y = to_string(a-b) + y;
        si++;
        xi++;
    }
    reverse(all(x));
    reverse(all(sum));
    if(sum != add(y, x)) cout << -1 << endl;
    else cout << stoll(y) << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}