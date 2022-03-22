#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> is(26);
    for(int i=0; i<n; i++) is[s[i]-'a'].push_back(i+1);
    for(int i=0; i<n; i++) is[s[i]-'a'].push_back(i+n+1);

    long long ans = 0;
    int p = 0;
    for(int i=0; i<m; i++) {
        int c = t[i]-'a';
        if(is[c].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(is[c].begin(), is[c].end(), p);
        cout << p << endl;
        if(p >= n) {
            p -= n;
            ans += n;
        }
    }
    ans += p;
    cout << ans << endl;
    return 0;
}