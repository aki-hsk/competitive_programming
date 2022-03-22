#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    bool ans = false;

    // 先頭から何文字分連結するか？
    for(int i=0; i<=N; i++) {
        // 後半何文字目から連結するか
        for(int j=i; j<=N; j++) {
            string t = s.substr(0, i) + s.substr(j); //0からi文字とj文字以降
            if(t == "keyence") ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
