#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;

int main() {
    // N:県の数, M:市の数
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    vector<vector<int>> PY(N);
    rep(i, M) {
        cin >> P[i] >> Y[i];
        P[i]--;
        PY[P[i]].push_back(Y[i]);
    }

    // 県名ごとにソートをかます
    rep(i, N) {
        sort(PY[i].begin(), PY[i].end());
        PY[i].erase(unique(PY[i].begin(), PY[i].end()), PY[i].end());
    }

    // 出力
    rep(i, M) {
        printf("%06d", P[i] + 1);
        int ran = lower_bound(PY[P[i]].begin(), PY[P[i]].end(), Y[i]) - PY[P[i]].begin();
        printf("%06d\n", ran + 1) ;
    }
}