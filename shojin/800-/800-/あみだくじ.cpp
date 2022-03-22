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
    int n, l;
    // ws:（非書式化入力関数）空白文字を読み捨てるマニピュレータ(C++のストリームの形式を変えるための関数などのこと)
    cin >> n >> l >> ws;
    vector<string> v(l);
    string t;
    rep(i, l+1) {
        if(i == l) {
            getline(cin, t);
            break;
        }
        getline(cin, v[i]);
    }

    int goal;
    rep(i, t.size()) if(t[i] == 'o') goal = i;

    for(int start = 0; start <2*n-1; start += 2) {
        int p = start;
        for(int i=0; i<l; i++) {
            if(p-1 >= 0 && v[i][p-1] == '-') p -= 2;
            else if(p+1 < 2*n-1 && v[i][p+1] == '-') p += 2;
        }
        if(p == goal) {
            cout << start/2 + 1 << endl;
            return 0;
        }
    }
}