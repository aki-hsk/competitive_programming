#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()


// 双方向から挿入するのでdequeを使う
int main() {
    string s; int q;
    cin >> s >> q;
    deque<char> deq;
    for(auto tmp:s) deq.push_back(tmp);

    bool rev = false;
    rep(i, q) {
        int t;
        cin >> t;
        if(t == 1) rev = !rev;
        if(t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if(f == 1) {
                if(rev) deq.push_back(c);
                if(!rev) deq.push_front(c);
            }
            else if(f == 2) {
                if(rev) deq.push_front(c);
                if(!rev) deq.push_back(c);
            }
        }
    }
    string ans;
    for(auto tmp:deq) ans.push_back(tmp);
    if(rev) reverse(all(ans));
    cout << ans << endl;
}
