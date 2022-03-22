#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int c[3];
ll k;

int solve(ll N) {
    if(N % 3 == 0) return 0;
    if(N % 3 == 1) {
        if(c[1] >= 1 && k > 1) return 1;
        if(c[2] >= 2 && k > 2) return 2;
    }
    if(N % 3 == 2) {
        if(c[2] >= 1 && k > 1) return 1;
        if(c[1] >= 2 && k > 2) return 2;
    }
    return -1;
}

int main() {
    ll N;
    cin >> N;
    k = to_string(N).size();
    ll n = N;
    while (n) {
        int x = n % 10;
        c[x%3]++;
        n /= 10;
    }
    cout << solve(N) << endl;
}