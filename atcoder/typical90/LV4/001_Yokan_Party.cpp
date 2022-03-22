#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n+2);
    a[0] = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    a.back() = l;

    int left = 0, right = 1e9+1;

    // scoreをmid以上にできるか?
    while(right - left > 1) {
        int mid = (right + left) / 2;
        bool ok = true;
        int len = 0, cnt = 0;
        for(int i=1; i<=n+1; i++) {
            if(len >= mid && cnt < k) {
                cnt++;
                len = a[i] - a[i-1];
            }
            else len += a[i] - a[i-1];
        }
        if(cnt < k || len < mid) ok = false;

        if(ok) left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}