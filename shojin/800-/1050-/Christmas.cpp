#include<iostream>
using namespace std;

// https://drken1215.hatenablog.com/entry/2019/05/13/114600
// レベルが n のバーガーの下から x 枚に含まれるパティの量
long long rec(int n, long long x) {
    if(n==0) return 1;
    // レベルn-1のバーガーの長さ
    long long len = (1LL << (n+1)) - 3;
    // レベルn-1のパティーの量
    long long num  = (1LL<<n) - 1;
    if(x == 1) return 0;
    // xが真ん中より左
    else if(x <= len + 1) return rec(n-1, x-1);
    // xが真ん中
    else if(x == len + 2) return num + 1;
    // xが真ん中より右
    else if(x <= (len + 1)*2) return num + 1 + rec(n-1, x-len-2);
    // 右端
    else return num * 2 + 1;
}

int main() {
    int n; long long x;
    cin >> n >> x;
    cout << rec(n, x) << endl;
}