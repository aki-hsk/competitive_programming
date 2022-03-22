#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
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

    vector<pair<int, int>> seg;
    rep(i, n) {
        for(int j=p[i]; j<=n; j+=p[i]) {
            pair<int, int> p = {i, id[j]};
            seg.push_back(p);
        }
    }
    sort(seg.begin(), seg.end(), cmp);
    int m = seg.size();
	vector<int> tail(m);
	int l = 1;
	tail[0] = seg[0].second;
	for(int i = 1; i < m; ++i){
		int v = seg[i].second;
		auto it = lower_bound(tail.begin(), tail.begin() + l, v);
		if(it == tail.begin() + l)
			tail[l++] = v;
		else
			*it = v;
	}
	cout << l;
	return 0;
}