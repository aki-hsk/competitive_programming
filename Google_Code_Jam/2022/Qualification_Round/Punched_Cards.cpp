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

void solve(int num) {
    int r, c;
    cin >> r >> c;
    vector<string> board(2*r+1);

    string row0, row1;
    for(int j=0; j<c*2+1; j++) {
        if(j % 2 == 0) row0.push_back('+');
        else row0.push_back('-');

        if(j % 2 == 0) row1.push_back('|');
        else row1.push_back('.');
    }

    cout << "Case #" << num << ":" << endl;
    for(int i=0; i<r*2+1; i++) {
        for(int j=0; j<c*2+1; j++) {
            if(i == 0 && j == 0) cout << '.';
            else if(i == 0 && j == 1) cout << '.';
            else if(i == 1 && j == 0) cout << '.';
            else if(i % 2 == 0) cout << row0[j];
            else cout << row1[j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve(i+1);
}