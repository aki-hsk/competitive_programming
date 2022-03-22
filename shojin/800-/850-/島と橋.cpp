#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        total += a[i];
    }

    if(total % n != 0) {
        cout << -1 << endl;
        return 0;
    }

    int x = total / n;
    int ans = 0, sum = 0, cnt = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        cnt++;
        if(sum % cnt == 0 && sum/cnt == x) {
            ans += cnt -1;
            sum = 0;
            cnt = 0;
        }
    }
    cout << ans << endl;
}