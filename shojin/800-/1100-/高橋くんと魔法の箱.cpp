#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, bool> mp;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(mp[a[i]]) continue;
        ans++;
        for(int j=a[i]; j<=1e9; j+=j) {
            mp[j] = true;
        }
    }
    cout << ans << endl;
}