#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int ans = (1<<30);
    for(int bit = 0; bit<(1<<n); bit++) {
        int x = 0, y = 0;
        for(int i=0; i<n; i++) {
            y |= a[i];
            if(bit>>i&1) {
                x ^= y;
                y = 0;
            }
        }
        x ^= y;
        ans = min(ans, x);
    }
    cout << ans << endl;
}