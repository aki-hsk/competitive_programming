#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int main() {
    int n;
    cin >> n;
    vector<deque<int>> a(n);
    rep(i, n) rep(j, n-1) {
        int x;
        cin >> x;
        x--;
        a[i].push_back(x);
    }
    vector<pair<int, int>> q;
    auto push = [&](int i) {
        if(a[i].empty()) return;
        int j = a[i].front();
        if(a[j].empty()) return;
        if(i == a[j].front()) {
            pair<int, int> p = {min(i, j), max(i, j)};
            q.push_back(p);
        }
    };
    rep(i, n) push(i);

    int ans = 0;
    while(!q.empty()) {
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        vector<pair<int, int>> pre;
        swap(pre, q);
        for(auto p:pre) {
            int i = p.first;
            int j = p.second;
            a[i].pop_front();
            a[j].pop_front();
            push(i);
            push(j);
        }
        ans++;
    }
    rep(i, n) {
        if(!a[i].empty()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}