#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long sum(long long a, long long b) {
    if(a > b) swap(a, b);
    return (b-a+1)*(a+b)/2;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // 数列 aに含まれる mid 以上の値は K 個以下か？
    long long left = 0, right = 1e18;
    while(right - left > 1) {
        long long mid = (left + right)/2;
        long long cnt = 0;
        for(int i=0; i<n; i++) cnt += max(0LL, a[i]-mid+1);
        if(cnt < k) right = mid;
        else left = mid;
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        if(a[i] >= right) {
            ans += sum(right, a[i]);
            k -= a[i]-right+1;
        }
    }
    ans += k * (right-1);
    cout << ans << endl;
}