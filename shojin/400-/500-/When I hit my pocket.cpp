#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    if(b - a <= 2 || k <= a) {
        cout << 1 + k << endl;
        return 0;
    }
    cout << a + (k-a+1)/2*(b-a) + (k-a-1)%2 << endl;
}