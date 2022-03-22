#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<int> A = a;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i=0; i<n; i++) {
        a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin();
    }
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) vp[i] = {a[i], b[i]};
    sort(vp.begin(), vp.end(), compare);

    fenwick_tree<long long> fw(200005);
    long long ans = 0;
    int cnt = 1;
    for(int i=0; i<n; i++) {
        fw.add(vp[i].first, 1);
        if(i < n-1 && vp[i].first == vp[i+1].first && vp[i].second == vp[i+1].second) {
            cnt++;
            continue;
        }
        ans += fw.sum(0, vp[i].first + 1) * cnt;
        cnt = 1;
    }
    cout << ans << endl;
}

