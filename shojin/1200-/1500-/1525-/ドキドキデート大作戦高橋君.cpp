#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> s(m), t(m);
    for(int i=0; i<m; i++) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
        v[s[i]]++;
        v[t[i]+1]--;
    }
    for(int i=0; i<n; i++) v[i+1] += v[i];
    atcoder::fenwick_tree<int> fw(n+1);
    for(int i=0; i<n; i++) {
        if(v[i] > 1) fw.add(i, 1);
    }
    vector<int> ans;
    for(int i=0; i<m; i++) {
        int sum = fw.sum(s[i], t[i]+1);
        if(sum == t[i]-s[i]+1) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for(auto a:ans) cout << a << endl;
}