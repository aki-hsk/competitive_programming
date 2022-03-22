#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main() {
    // c:バスの定員, k:待てる時間
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    int res = 0;

    for(int i=0; i<n;) {
        ++res;
        int start = i;
        // whileを抜けるとバスが一台増える
        while(i < n && t[i]-t[start] <= k && i - start < c) ++i;
    }
    cout << res << endl;
}