#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // 累積和と連想配列
    vector<long long> s(n+1, 0);
    map<long long, long long> nums;
    for(int i=0; i<n; i++) s[i+1] = s[i] + a[i];
    for(int i=0; i<n+1; i++) nums[s[i]]++;

    long long res = 0;
    for(auto it:nums) {
        long long num = it.second;
        res += num * (num - 1) / 2;
    }
    cout << res << endl;
}