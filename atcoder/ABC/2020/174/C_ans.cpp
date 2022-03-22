#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int k;
    cin >> k;
    int x = 7 % k;
    for(int i=1; i<=k; i++) {
        if(x == 0) {
            cout << i << endl;
            return 0;
        }
        x = (x*10+7) % k;
    }
    cout << -1 << endl;
    return 0;
}