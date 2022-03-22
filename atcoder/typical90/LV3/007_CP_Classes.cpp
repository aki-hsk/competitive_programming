#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+2);
    a[0] = -INF;
    for(int i=1; i<=n; i++) cin >> a[i];
    a[n+1] = INF;
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    for(int qi=0; qi<q; qi++) {
        int b;
        cin >> b;
        int j = lower_bound(a.begin(), a.end(), b) - a.begin();
        ll ans = min(abs(b-a[j]), abs(b-a[j-1]));
        printf("%lld\n", ans);
    }
}
