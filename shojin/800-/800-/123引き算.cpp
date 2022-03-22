#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
long long const mod = 10000000000+7;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    // 基本3跳びをするNGの場合は-1する
    if(n == a || n == b || n == c) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i=0; i<100; i++) {
        if(n-3 != a && n-3 != b && n-3 != c) n -= 3;
        else if(n-2 != a && n-2 != b && n-2 != c) n -= 2;
        else if(n-1 != a && n-1 != b && n-1 != c) n -= 1;
    }

    if(n <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}