#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s[3];
    int x[3] = {};  // 3人のカードの位置を保存しておく
    int t = 0;      // t:現在のターンの人を表す {0:A, 1:B, 2:C}
    rep(i, 3) cin >> s[i];
    while(s[t][x[t]]) t = s[t][x[t]++] - 'a';
    cout << char('A' + t) << endl;
}
