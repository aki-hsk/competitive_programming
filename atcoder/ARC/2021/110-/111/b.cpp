#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MX = 200005;
int n, a[MX], b[MX], un[MX*2], e, p[MX*2], ans;
bool m[MX*2];
map<int,int> zp;
int find(int x){return (p[x] < 0 ? x : p[x] = find(p[x]));}
void uni(int x, int y){
	x = find(x); y = find(y);
	if(x != y){
		if(p[x] > p[y]) swap(x, y);
		p[x] += p[y];
		p[y] = x;
		m[x] |= m[y];
	}else m[x] = true;
}
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d%d", a+i, b+i);
		un[i*2] = a[i];
		un[i*2+1] = b[i];
	}
	sort(un,un+n*2);
	e = (int)(unique(un,un+n*2) - un);
	rep(i,e) zp[un[i]] = i;
	fill(p,p+e,-1);
	rep(i,n) uni(zp[a[i]],zp[b[i]]);
	rep(i,e) if(!m[find(i)]){
		m[find(i)] = true;
		ans--;
	}
	printf("%d\n", ans+e);
}