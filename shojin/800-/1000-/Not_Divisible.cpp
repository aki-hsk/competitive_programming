#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int M = *max_element(a.begin(), a.end());
    vector<bool> dp(M + 1, true);
    map<int, int> mp;

    for(int i=0; i<n; i++) {
        if(mp[a[i]] != 0) {
            dp[a[i]] = false;
            continue;
        }
        mp[a[i]]++;
        for(int j=a[i] * 2; j<=M; j+=a[i]) {
            dp[j] = false;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) if(dp[a[i]]) ans++;
    cout << ans << endl;
}