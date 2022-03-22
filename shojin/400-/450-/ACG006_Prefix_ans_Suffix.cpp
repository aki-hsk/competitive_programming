#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    bool flg;
    int ans = 2 * N;
    for(int i=0; i<N; i++) {
        flg = true;
        for(int j=0; j+i<N; j++) {
            if(s[i+j] != t[j]) flg = false;
        }
        if(flg) {
            ans -= N-i;
            break;
        }
    }
    cout << ans << endl;
}
