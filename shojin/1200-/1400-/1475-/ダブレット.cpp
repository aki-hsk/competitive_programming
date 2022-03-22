#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int diff(string a, string b) {
    int cnt = 0;
    for(int i=0; i<(int)a.size(); i++) {
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main() {
    int n;
    string s, t;
    cin >> s >> t >> n;
    vector<string> v;
    v.push_back(s);
    rep(i, n) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(t);

    vector<int> dist(n+2, -1);
    vector<int> pre(n+2, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<n+2; i++) {
            if(dist[i] != -1) continue;
            int d = diff(v[x], v[i]);
            if(d > 1) continue;
            dist[i] = dist[x] + d;
            q.push(i);
            pre[i] = x;
        }
    }

    cout << (dist[n+1] > 0 ? dist[n+1]-1 : dist[n+1]) << endl;
    if(dist[n+1] == -1) return 0;

    int p = n+1;
    vector<string> ans;
    do {
        ans.push_back(v[p]);
        p = pre[p];
    } while(p != -1);
    reverse(ans.begin(), ans.end());
    for(auto a:ans) cout << a << endl;
}