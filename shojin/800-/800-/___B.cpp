#include<iostream>
using namespace std;
using ll = long long;

int main() {
    ll b, c;
    cin >> b >> c;
    ll p_min = b - c/2;
    ll p_max = b + (c-2)/2;
    ll n_min = -b - (c-1)/2;
    ll n_max = -b + (c-1)/2;

    // max(0LL, min(n_max, p_max) - max(n_min, p_min) + 1) ここでB < 0 と B >= 0のときを考慮している
    ll ans = (n_max - n_min + 1) + (p_max - p_min + 1) - max(0LL, min(n_max, p_max) - max(n_min, p_min) + 1);
    cout << ans << endl;
}