#include<iostream>
#include<atcoder/all>
#include<vector>
#include<algorithm>
using namespace std;
using namespace atcoder;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        vp[i] = {a, b};
    }
    reverse(vp.begin(), vp.end());
    vector<long long> ans(m);
    ans[0] = n * (n-1) / 2;

    dsu ds(n);
    for(int i=1; i<m; i++) {
        int a = vp[i-1].first;
        int b = vp[i-1].second;
        if(ds.same(a, b)) ans[i] = ans[i-1];
        else {
            ans[i] = ans[i-1] - (long long)(ds.size(a) * ds.size(b));
            ds.merge(a, b);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<m; i++) cout << ans[i] << endl;
}