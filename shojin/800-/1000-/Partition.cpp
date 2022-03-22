#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 1;
    for(int a=1; a*a<=m; a++) {
        if(m % a != 0) continue;
        int b = m/a;
        if(b >= n) ans = max(ans, a);
        if(a >= n) ans = max(ans, b);
    }
    cout << ans << endl;
}