#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    long long m = (1<<30), M = -1;
    for(int i=0; i<n; i++) {
        m = min(m, a[i]);
        M = max(M, a[i]-m);
    }
    int ans = 0;
    m = (1<<30);
    for(int i=0; i<n; i++) {
        m = min(m, a[i]);
        if(a[i]-m == M) ans++;
    }
    cout << ans << endl;
}