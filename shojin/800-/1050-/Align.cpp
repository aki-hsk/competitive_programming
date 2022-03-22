#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(n % 2==0) {
        long long res = 0;
        for(int i=0; i<n/2-1; i++) res += 2*a[n-1-i];
        for(int i=0; i<n/2-1; i++) res -= 2*a[i];
        res += a[n/2] - a[n/2-1];
        cout << res << endl;
        return 0;
    }
    else {
        long long res1 = 0, res2 = 0;
        for(int i=0; i<n/2; i++) res1 -= a[i]*2;
        for(int i=n/2; i<n/2+2; i++) res1 += a[i];
        for(int i=n/2+2; i<n; i++) res1 += a[i]*2;

        for(int i=0; i<n/2; i++) res2 += a[n-1-i]*2;
        for(int i=n/2; i<n/2+2; i++) res2 -= a[n-1-i];
        for(int i=n/2+2; i<n; i++) res2 -= a[n-1-i]*2;
        cout << max(res1, res2) << endl;
        return 0;
    }
}