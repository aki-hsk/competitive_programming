#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main(){
    int N;
    cin >> N;
    vector<string> V;
    // 文字列を逆順にして入力
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        reverse(all(s));
        V.push_back(s);
    }

    // ソート
    sort(all(V));

    // 出力時に逆さまにした文字列を元に戻す
    rep(i, N) {
        reverse(all(V[i]));
        cout << V[i] << endl;
    }
}