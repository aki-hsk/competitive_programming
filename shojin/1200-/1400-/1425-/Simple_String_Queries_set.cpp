#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int>> v(26);
    rep(i, n) {
        v[s[i]-'a'].insert(i);
    }

    rep(k, q) {
        int t;
        cin >> t;
        if(t == 1) {
            // i文字目をcに変更
            int i;
            char c;
            cin >> i >> c;
            i--;
            v[s[i]-'a'].erase(i);
            s[i] = c;
            v[s[i]-'a'].insert(i);
        }
        else if(t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            rep(j, 26) {
                auto it = v[j].lower_bound(l);
                if(it != v[j].end() && *it < r) ++ans;
            }
            printf("%d\n", ans);
        }
    }
}