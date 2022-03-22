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
    int times;
    cin >> times;
    rep(i, times) {
        int n;
        cin >> n;
        vector<int> w(n);
        ll one_cnt = 0, two_cnt = 0;
        rep(i, n) {
            cin >> w[i];
            if(w[i] == 1) one_cnt++;
            else if(w[i] == 2) two_cnt++;
        }
        bool flg = false;
        if(one_cnt % 2 == 0 && two_cnt % 2 == 0) flg = true;
        if(one_cnt > 0 && one_cnt % 2 == 0 && two_cnt % 2 == 1) flg = true;
        cout << (flg ? "YES" : "NO") << endl;
    }
}