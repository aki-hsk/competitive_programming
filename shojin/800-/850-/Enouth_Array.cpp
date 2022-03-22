#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

// しゃくとり法 !!!
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0, ans = 0;
    int right = 0;
    for(int i=0; i<n; i++) {
        while(right < n && sum + a[right] < k) {
            sum += a[right];
            right++;
        }
        ans += n - right;
        sum -= a[i];
    }
    cout << ans << endl;
}