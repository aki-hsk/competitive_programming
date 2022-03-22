#include<iostream>
#include<vector>
using namespace std;

// 1回の操作では最大+2まで
// 回転する境界部分のみ変わる

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int score = 0;
    for(int i=0; i<n-1; i++) {
        if(s[i] == s[i+1]) score++;
    }
    int ans = min(score + 2*k, n-1);
    cout << ans << endl;
}