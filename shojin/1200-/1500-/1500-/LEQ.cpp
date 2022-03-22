#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int i=0; i<n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    const int M = 300005;
    fenwick_tree<mint> fw(M);
    mint ans = 0;
    mint two = 1, itwo = 1;
    for(int i=0; i<n; i++) {
        ans += two * fw.sum(0, a[i]+1);
        two *= 2;
        itwo /= 2;
        fw.add(a[i], itwo);
    }
    cout << ans.val() << endl;
    return 0;
}