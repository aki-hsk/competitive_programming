#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int keta(ll n) {
    int k = 0;
    if(n == 0) return 1;
    while(n) {
        n /= 10;
        k++;
    }
    return k;
}

int main() {
    ll A, B, X;
    cin >> A >> B >> X;
    // 2分探索
    int left = 0, right = 1e9+1;
    while(right-left > 1) {
        int mid = (right + left) / 2;
        ll n = A * mid + B * keta(mid);
        if(X >= n) left = mid;
        else right = mid;
    }
    cout << left << endl;
}