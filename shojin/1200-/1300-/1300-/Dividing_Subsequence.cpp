#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;

bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int LIS(vector<long long> &a) {
    int n = (int)a.size();
    // dpi[k]:=dpi[k]:=  最初の i項のみを考えた場合の単調増加な部分列であって、長さ k+1 であるようなもののうち、その最後の要素の最小値
    vector<long long> dp(n, INF);
    for(int i=0; i<n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    vector<int> id(n+1);
    rep(i, n) cin >> p[i];
    rep(i, n) {
        cin >> q[i];
        id[q[i]] = i;
    }

    vector<pair<int, int>> vp;
    rep(i, n) {
        for(int j=p[i]; j<=n; j+=p[i]) {
            pair<int, int> p = {i, id[j]};
            vp.push_back(p);
        }
    }
    sort(vp.begin(), vp.end(), cmp);
    int m = vp.size();
    vector<long long> a(m);
    for(int i=0; i<m; i++) a[i] = vp[i].second;
    cout << LIS(a) << endl;
	return 0;
}