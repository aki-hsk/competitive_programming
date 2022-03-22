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
    int si, sj;
    cin >> si >> sj;
    int tile[50][50], point[50][50];
    rep(i, 50) rep(j, 50) cin >> tile[i][j];
    rep(i, 50) rep(j, 50) cin >> point[i][j];

    int N = 2500;
    vector<bool> seen(N, false);
    stack<pair<int, int>> st;

    seen[tile[si][sj]] = true;  // 初期地点は探索済み
    st.push(make_pair(si, sj));
    string ans;

    while(!st.empty()) {
        // stackから頂点を取り出す
        int iy = st.top().first;
        int ix = st.top().second;
        st.pop();

        for(int i=0; i<4; i++) {
            int y = dy[i] + iy;
            int x = dx[i] + ix;
            if(y < 0 || y >= 50 || x < 0 || x >= 50) continue;
            if(seen[tile[y][x]]) continue;
            if(dy[i] == 1 && dx[i] == 0) ans.push_back('D');
            if(dy[i] == -1 && dx[i] == 0) ans.push_back('U');
            if(dy[i] == 0 && dx[i] == 1) ans.push_back('R');
            if(dy[i] == 0 && dx[i] == -1) ans.push_back('L');
            seen[tile[y][x]] = true;
            st.push(make_pair(y, x));
        }
    }
    cout << ans << endl;
}
