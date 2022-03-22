#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string S, T;
    cin >> S >> T;
    // ma: S->Tの変換
    // ima: T->Sの変換
    map<char, char> st, ts;
    bool flg = true;

    for(int i=0; i<S.size(); i++) {
        char s = S[i], t = T[i];
        if(st.count(s) && st[s] != t) flg = false;
        if(ts.count(t) && ts[t] != s) flg = false;
        st[s] = t; ts[t] = s;
    }
    cout << (flg ? "Yes" : "No") << endl;
}