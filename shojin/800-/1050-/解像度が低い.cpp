#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int cnt = 1, ans = 0;
    for(int i=0; i<n; i++) {
        while(i+1 < n && a[i] < a[i+1]) {
            cnt++;
            i++;
        }
        if(cnt >= k) ans += cnt - k + 1;
        cnt = 1;
    }
    cout << ans << endl;
}