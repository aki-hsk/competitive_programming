#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
                // 都市, 点数, 番号
    vector<tuple<string, int, int>> a;

    for(int i=1; i<=N; i++) {
        string s;
        int p;
        cin >> s >> p;
        // 降順ソートのために正負を反転
        p = -p;

        // tieでtupleを作る
        // 作ったものをvectorに突っ込む
        a.push_back(tie(s,p,i));
    }
    sort(a.begin(), a.end());

    rep(i, N) {
        cout << get<2>(a[i]) << endl;
    }
    // tupleのソートは1要素目、2要素目, 3要素目の順で比較
}
