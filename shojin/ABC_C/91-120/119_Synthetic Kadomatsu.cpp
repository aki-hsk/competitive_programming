#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, A, B, C;
vector<int> L;

int dfs(int i, int a, int b, int c) {
    if(i == N) {
        if(!a || !b || !c) return INF;  // a,b,cいずれも竹は１本か必ず使ってないといけない
        return abs(a - A) + abs(b - B) + abs(c - C); // 合成してできたa, b, cをA,B,Cにするコスト
    }
    int res = dfs(i+1, a, b, c);

    // A, B, Cを使う場合
    chmin(res, dfs(i+1, a + L[i], b, c) + (a ? 10 : 0));
    chmin(res, dfs(i+1, a, b + L[i], c) + (a ? 10 : 0));
    chmin(res, dfs(i+1, a, b, c + L[i]) + (a ? 10 : 0));

    return res;
}

int main() {
    // N:竹の本数
    // A, B, C: 目標の竹の長さ
    cin >> N >> A >> B >> C;
    L.resize(N);
    for(int i=0; i<N; i++) cin >> L[i];
    cout << dfs(0, 0, 0, 0) << endl;
}