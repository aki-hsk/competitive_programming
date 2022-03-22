#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        ll n;
        cin >> n;
        if(n % 4 == 0) cout << "Even" << endl;
        else if(n % 2 == 0) cout << "Same" << endl;
        else cout << "Odd" << endl;
    }
}