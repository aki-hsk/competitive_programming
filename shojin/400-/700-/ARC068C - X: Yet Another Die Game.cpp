#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    // εγδΈγ, a/b -> a+b-1/b
    cout << (x/11)*2 + ((x%11+5)/6) << endl;
}