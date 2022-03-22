#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<long long, long long>> vp(n);
    vector<long long> s(n+1);
    for(int i=0; i<n; i++) cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end());
    vector<long long> x(n);
    for(int i=0; i<n; i++) x[i] = vp[i].first;

    long long ans = 0;
    for(int i=0; i<n; i++) {
        vp[i].second += s[i];
        if(vp[i].second > 0) {
            // 爆発範囲の右端, 左端はx[i]
            long long nb = vp[i].first + 2 * d;
            int np = upper_bound(x.begin(), x.end(), nb) - x.begin();
            long long cnt = (vp[i].second + a - 1) / a;
            s[i] -= cnt * a;
            s[np] += cnt * a;
            ans += cnt;
        }
        s[i+1] += s[i];
    }
    cout << ans << endl;
}