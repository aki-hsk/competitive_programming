#include<iostream>
#include<vector>
using namespace std;

long long dp[2005][2005];

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int ans = -(1<<31);
    ans = max(ans, abs(a[n-1]-w));
    if(n > 1) ans = max(ans, abs(a[n-2]-a[n-1]));
    cout << ans << endl;
    return 0;
}