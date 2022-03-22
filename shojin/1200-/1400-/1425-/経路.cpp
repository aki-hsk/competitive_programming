#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint factorial(int x) {
    mint res = 1;
    while(x) {
        res *= x;
        x--;
    }
    return res;
}

int main() {
    int w, h;
    cin >> w >> h;
    mint res = factorial(w + h - 2) / (factorial(w - 1) * factorial(h - 1));
    cout << res.val() << endl;
    return 0;
}