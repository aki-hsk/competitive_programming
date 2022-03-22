#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    map<int, int> mp;
    long long sum = 0;
    mp[sum] = 1;
    for(int i=0; i<n; i++) {
        sum = (sum + a[i]) % m;
        mp[sum]++;
    }
    long long res = 0;
    for(auto m:mp) {
        res += ((long long)m.second * (m.second-1)) / 2;
    }
    cout << res << endl;
    return 0;
}