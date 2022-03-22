#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
    string s;
    cin >> sn;
    int n = s.size();
    vector<int> ans(n);
    rep(ri, 2) {
        {
            int cnt = 0;
            rep(i, n) {
                if(s[i] == 'R') cnt++;
                else {
                    ans[i] += cnt/2;
                    ans[i-1] += (cnt+1)/2;
                    cnt = 0;
                }
            }
        }
        reverse(all(ans));
        reverse(all(s));
        rep(i, n) {
            if(s[i] == 'L') s[i] = 'R';
            else s[i] = 'L';
        }
    }
    rep(i, n) {
        printf("%d%c", ans[i], i==n-1 ? '\n' : ' ');
    }
    return 0;
}