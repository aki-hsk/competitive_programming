#include<iostream>
#include<vector>
#include<map>
using namespace std;

// i<j
// j-i = a[i]+a[j]
// a[i]+i = a[j]-j

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    long long ans = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        mp[a+i]++;
        ans += mp[i-a];
    }
    cout << ans << endl;
}