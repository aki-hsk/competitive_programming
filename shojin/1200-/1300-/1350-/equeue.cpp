#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int ans = 0;
    for(int l=0; l<n+1; l++) {
        for(int r=0; r<n+1; r++) {
            if(n < l+r) continue;
            int re = k - (l+r);
            if(re < 0) continue;
            vector<int> t;
            for(int i=0; i<l; i++) t.push_back(v[i]);
            for(int i=0; i<r; i++) t.push_back(v[n-1-i]);
            sort(t.begin(), t.end());

            int sum = accumulate(t.begin(), t.end(), 0);
            for(int i=0; i<min(re, (int)t.size()); i++) {
                if(t[i] >= 0) break;
                sum -= t[i];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}