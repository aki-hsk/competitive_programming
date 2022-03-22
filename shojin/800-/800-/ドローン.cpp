#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    int t;
    cin >> s >> t;
    int hor = 0, ver = 0, question_cnt = 0;

    rep(i, s.size()) {
        if(s[i] == 'R') hor++;
        else if(s[i] == 'L') hor--;
        else if(s[i] == 'U') ver++;
        else if(s[i] == 'D') ver--;
        else if(s[i] == '?') question_cnt++;
    }

    int dist = abs(ver) + abs(hor);
    // max
    if(t == 1) {
        cout << dist + question_cnt << endl;
    }

    // min
    else {
        int ans;
        ans = dist - question_cnt;
        if(dist - question_cnt < 0) ans = abs(dist-question_cnt)%2;
        cout << ans << endl;
    }
}