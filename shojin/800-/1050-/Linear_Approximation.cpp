#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i]-i+1;
    }

    sort(b.begin(), b.end());
    int median = b[n/2];
    long long ans = 0;
    for(int i=0; i<n; i++) {
        ans += abs(b[i]-median);
    }
    cout << ans << endl;
}