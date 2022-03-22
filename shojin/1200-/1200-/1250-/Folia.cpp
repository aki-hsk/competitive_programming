#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0; i<n+1; i++) cin >> a[i];
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    long long branch = 1;
    long long ans = 0;
    for(int i=0; i<n+1; i++) {
        ans += branch;
        branch -= a[i];
        if(branch < 0) {
            cout << -1 << endl;
            return 0;
        }
        tot -= a[i];
        branch = min(branch * 2, tot);
    }
    cout << ans << endl;
}