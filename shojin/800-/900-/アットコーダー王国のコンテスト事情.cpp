#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int mod = 1000000007;

long long factorial(int m) {
    long long res = 1;
    for(int i=1; i<=m; i++) {
        res *= i;
        res %= mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> t[i];
        mp[t[i]]++;
    }
    sort(t.begin(), t.end());
    long long ans = 0;
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += t[i];
        ans += sum;
    }

    long long ans2 = 1;
    for(auto m:mp) {
        ans2 *= factorial(m.second);
        ans2 %= mod;
    }
    cout << ans << endl;
    cout << ans2 << endl;
}