#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll left = 0, right = (ll)3e9;
    while(right - left > 1) {
        ll mid = (left + right)/2;
        ll cost = mid*(mid+1)/2;
        if(cost > n+1) right = mid;
        else if( cost <= n+1) left = mid;
    }
    cout << n - left + 1 << endl;
}