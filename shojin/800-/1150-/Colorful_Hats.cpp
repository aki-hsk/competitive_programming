#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // 何通りあるかの分布
    vector<int> c(n+1);
    c[0] = 3;
    long long ans = 1;
    for(int i=0; i<n; i++) {
        if(!c[a[i]]) {
            cout << "0" << endl;
            return 0;
        }
        ans *= c[a[i]];
        c[a[i]]--;
        c[a[i]+1]++;
        ans %= 1000000007;
    }
    cout << ans << endl;
}