#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> b(m), idol(m);
    for(int i=0; i<m; i++) {
        cin >> b[i];
        int c;
        cin >> c;
        int sum = 0;
        for(int j=0; j<c; j++) {
            int x;
            cin >> x;
            x--;
            sum |= (1<<x);
        }
        idol[i] = sum;
    }

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++) {
        if(__builtin_popcount(bit) != 9) continue;
        int score = 0;
        for(int j=0; j<n; j++) {
            if(bit>>j&1) score += a[j];
        }
        for(int j=0; j<m; j++) {
            if(__builtin_popcount(bit&idol[j]) >= 3) {
                score += b[j];
            }
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
}