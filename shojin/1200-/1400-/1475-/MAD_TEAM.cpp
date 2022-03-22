#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 5;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[i][j];

    int l = 0, r = 1e9+1;
    while(r-l > 1) {
        int mid = (l + r) / 2;
        vector<int> s;
        for(int i=0; i<n; i++) {
            int x = 0;
            for(int j=0; j<m; j++) {
                if(a[i][j] >= mid) x |= 1<<j;
            }
            s.push_back(x);
        }
        // sは高々32通り
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        bool ok = false;
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<s.size(); j++) {
                for(int k=0; k<s.size(); k++) {
                    if((s[i]|s[j]|s[k]) == (1<<m)-1) ok = true;
                }
            }
        }
        if(ok) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}