#include <bits/stdc++.h>
using namespace std;
const int SINF = 1LL << 29;
#define rep(i, n) for(int i = 0; i < (n); ++i)

void output(vector<pair<int, int>> ans) {
    for(auto p:ans) {
        printf("%d %d\n", p.first, p.second);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ans(n);
    rep(i, n) {
        ans[i].first = i*2 + 1;
        ans[i].second = (i+1) * 2;
    }
    if(m == 0) {
        output(ans);
        return 0;
    }
    if(m > n-2 || m < 0) {
        cout << -1 << endl;
        return 0;
    }
    ans[n-2-m].second = 1e8;
    output(ans);
}