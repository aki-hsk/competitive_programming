#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for(int i=0; i<n; i++) {
        cin >> s[i];
        if(s[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }

    int ans = 0, right = 0;
    long long x = 1;
    for(int left=0; left<n; left++) {
        while(right < n && x * s[right] <= k) {
            x *= s[right];
            right++;
        }
        ans = max(ans, right-left);
        if(left == right) right = left + 1;
        else x /= s[left];
    }
    cout << ans << endl;
}