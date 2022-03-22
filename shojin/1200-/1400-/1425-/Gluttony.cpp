#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n), f(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());

    long long left = -1, right = 1e18 + 1;
    // NG --- mid --- OK
    while(right - left > 1) {
        // 最大値の値をmidにできるか？
        long long k = K;
        long long mid = (right + left) / 2;
        for(int i=0; i<n; i++) {
            if(a[i] * f[i] > mid) {
                k -= a[i]-mid/f[i];
            }
        }
        if(k < 0) left = mid;
        else right = mid;
    }
    cout << right << endl;
    return 0;
}