#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    int max_a = *max_element(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(b[i] > max_a) {
            h -= b[i];
            ans++;
        }
        if(h <= 0) {
            cout << ans << endl;
            return 0;
        }
    }

    if(h > 0) ans += (h+max_a-1)/max_a;
    cout << ans << endl;
}