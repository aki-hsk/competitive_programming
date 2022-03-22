#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans1 = b * d;
    ll ans2 = a * c;
    ll ans3 = a * d;
    ll ans4 = b * c;

    ll ans = max({ans1, ans2, ans3, ans4});
    cout << ans << endl;

}