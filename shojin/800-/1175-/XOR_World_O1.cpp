#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://drken1215.hatenablog.com/entry/2019/03/09/224100


ll oddsolve(ll a) { return (a+1)/2 % 2; }
ll solve(ll a) {
    if(a % 2 == 1) return oddsolve(a);
    else return oddsolve(a+1) ^ (a+1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << (solve(b) ^ solve(a-1)) << endl;
}