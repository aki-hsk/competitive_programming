#include<iostream>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

// 暗証番号の種類は000~999までの1000種類なのでこれを全て探索する
// O(n)
int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    for(int i=0; i<1000; i++) {
        string t;
        int x = i;
        // tを3桁でゼロ埋めする 0埋め
        rep(j, 3){
            t = char(x%10+'0') + t;
            x /= 10;
        }
        int index = 0;
        rep(i, s.size()) {
            if(s[i] == t[index]) index++;
            if(index == 3) break;
        }
        if(index == 3) ans++;
    }
    cout << ans << endl;
}