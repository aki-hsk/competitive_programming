#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

const int M = 100005;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(M);
    int sum = 0;
    for(int i=0; i<n; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        v[l] += s;
        v[r+1] -= s;
        sum += s;
    }
    for(int i=1; i<M; i++) v[i] += v[i-1];

    for(int i=1; i<=m; i++) {
        if(v[i] == 0) {
            cout << sum << endl;
            return 0;
        }
    }

    int ans = 0;
    for(int i=1; i<=m; i++) {
        ans = max(ans, sum-v[i]);
    }
    cout << ans << endl;
    return 0;
}