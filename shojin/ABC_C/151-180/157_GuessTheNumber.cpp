#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    // N: 桁数, M: 入力数
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        s[i] = a;
        c[i] = b;
    }

    int ans = -1;
    for(int i=0; i<=1000; i++) {
        string t = to_string(i);
        bool flg = true;
        if(t.size() != N) continue;
        for(int j=0; j<M; j++) {
            int a = s[j];
            if((t[a]-'0') != c[j]) {
                flg = false;
                break;
            }
        }
        if(flg) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
