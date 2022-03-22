#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return 1;} return 0;}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    long long x2 = 0;
    rep(i, n) {
        if(i&1) x2 -= a[i];
        else x2 += a[i];
    }
    vector<int> ans(n);
    ans[0] = x2/2;
    rep(i, n-1) {
        ans[i+1] = a[i]-ans[i];
    }
    rep(i, n) ans[i] *= 2;
    rep(i, n) cout << ans[i] << endl;
}