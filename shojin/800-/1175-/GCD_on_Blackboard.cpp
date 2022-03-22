#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> l_gcd(n+1), r_gcd(n+1);
    for(int i=0; i<n; i++) l_gcd[i+1] = __gcd(l_gcd[i], a[i]);
    for(int i=n-2; i>=0; i--) r_gcd[i] = __gcd(r_gcd[i+1], a[i+1]);
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, __gcd(l_gcd[i], r_gcd[i]));
    cout << ans << endl;
}