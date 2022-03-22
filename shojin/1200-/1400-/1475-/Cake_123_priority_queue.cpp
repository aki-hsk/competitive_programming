#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int x, y, z, K;
    cin >> x >> y >> z >> K;
    vector<long long> a(x), b(y), c(z);
    for(int i=0; i<x; i++) cin >> a[i];
    for(int i=0; i<y; i++) cin >> b[i];
    for(int i=0; i<z; i++) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    priority_queue<vector<long long>> pq;
    map<vector<long long>, bool> mp;
    pq.push({a[0]+b[0]+c[0], 0, 0, 0});

    int cnt = 0;
    int na = -1, nb = -1, nc = -1;
    while(cnt < K) {
        vector<long long> now = pq.top(); pq.pop();
        if(mp[now]) continue;
        mp[now] = true;
        na = now[1], nb = now[2], nc = now[3];
        printf("%lld\n", now[0]);
        cnt++;
        if(na + 1 < x) pq.push({a[na+1]+b[nb]+c[nc], na+1, nb, nc});
        if(nb + 1 < y) pq.push({a[na]+b[nb+1]+c[nc], na, nb+1, nc});
        if(nc + 1 < z) pq.push({a[na]+b[nb]+c[nc+1], na, nb, nc+1});
    }
    return 0;
}