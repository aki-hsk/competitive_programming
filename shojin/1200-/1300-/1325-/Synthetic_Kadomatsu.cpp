#include<iostream>
#include<vector>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int N, A, B, C;
vector<int> l;

int dfs(int i, int a, int b, int c) {
    if(i == N) {
        if(!a || !b || !c) return (1<<30);
        return abs(a-A) + abs(b-B) + abs(c-C);
    }
    // 今ある竹を採用しない場合
    int res = dfs(i+1, a, b, c);
    chmin(res, dfs(i+1, a+l[i], b, c) + (a ? 10 : 0));
    chmin(res, dfs(i+1, a, b+l[i], c) + (b ? 10 : 0));
    chmin(res, dfs(i+1, a, b, c+l[i]) + (c ? 10 : 0));

    return res;
}

int main() {
    cin >> N >> A >> B >> C;
    l.resize(N);
    for(int i=0; i<N; i++) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
}