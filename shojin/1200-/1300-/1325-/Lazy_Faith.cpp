#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF = (1LL<<59);

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<long long> s(a), t(b);
    for(int i=0; i<a; i++) cin >> s[i];
    for(int i=0; i<b; i++) cin >> t[i];
    s.push_back(INF);
    s.push_back(-INF);
    t.push_back(INF);
    t.push_back(-INF);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i=0; i<q; i++) {
        long long x;
        cin >> x;
        int is = lower_bound(s.begin(), s.end(), x) - s.begin();
        long long ms = s[is-1];
        long long Ms = s[is];
        int it = lower_bound(t.begin(), t.end(), x) - t.begin();
        long long mt = t[it-1];
        long long Mt = t[it];
        long long dist = INF;
        dist = min(dist, max(Mt-x, Ms-x));
        dist = min(dist, (Ms-x)*2+x-mt);
        dist = min(dist, (Mt-x)*2+x-ms);
        dist = min(dist, (x-ms)*2+Mt-x);
        dist = min(dist, (x-mt)*2+Ms-x);
        dist = min(dist, max(x-mt, x-ms));
        cout << dist << endl;
    }
}