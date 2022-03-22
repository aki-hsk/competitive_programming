#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

// 適当な頂点を根とした木で考える
// 一番大きい値を根に書き、そこからDFSなりBFSなりで大きい順に値を書き込んでいく
// すべての辺で値は親の方が子より大きくなるので、子の値はそれぞれ一回ずつスコアになる
// すると、最大値以外がそれぞれ一回ずつ現れるので最大になる

vector<vector<int>> g;
int main() {
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());

    queue<int> q;
    q.push(0);
    vector<int> ans(n, -1);
    int i=0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        ans[v] = c[i++];
        for(auto nv:g[v]) {
            if(ans[nv] != -1) continue;
            q.push(nv);
        }
    }

    long long tot = accumulate(c.begin()+1, c.end(), 0);
    cout << tot << endl;
    for(auto a:ans) cout << a << endl;
}