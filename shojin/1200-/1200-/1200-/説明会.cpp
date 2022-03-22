#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++) cin >> s[i];
    sort(s.rbegin(), s.rend());

    int q;
    cin >> q;
    for(int qi=0; qi<q; qi++) {
        int k;
        cin >> k;
        int ans = s[k];
        if(s[k] != 0) ans++;
        cout << ans << endl;
    }
    return 0;
}