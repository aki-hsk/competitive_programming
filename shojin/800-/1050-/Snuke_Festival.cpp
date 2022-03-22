#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    for(int i=0; i<n; i++) {
        long long top_cnt = lower_bound(a.begin(), a.end(), b[i])-a.begin();
        long long bottom_cnt = n - (int)(upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        ans += top_cnt * bottom_cnt;
    }
    cout << ans << endl;
}