#include<iostream>
using namespace std;

// 10->2進数への変換
// http://www.infonet.co.jp/ueyama/ip/binary/dec2bin.html

int main() {
    int n;
    cin >> n;
    string ans;
    while(n) {
        if(n % 2 != 0) {
            ans = '1' + ans;
            n--;
        }
        else ans = '0' + ans;
        n /= -2;
    }
    if(ans.empty()) ans = "0";
    cout << ans << endl;
}