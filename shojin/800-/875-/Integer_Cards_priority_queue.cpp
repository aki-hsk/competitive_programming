#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    priority_queue<pair<int, int>> q;
    rep(i, n) q.push(make_pair(a[i], 1));
    rep(i, m) {
        int b, c;
        cin >> b >> c;
        q.push(make_pair(c, b));
    }
    ll ans = 0;
    rep(i, n) {
        auto p = q.top();
        q.pop();
        ans += p.first;
        if(p.second > 1) {
            p.second--;
            q.push(p);
        }
    }
    cout << ans << endl;
}