#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF = 1LL<<60;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int LIS(vector<long long> &a) {
    int n = (int)a.size();
    // dpi[k]:=dpi[k]:=  最初の i項のみを考えた場合の単調増加な部分列であって、長さ k+1 であるようなもののうち、その最後の要素の最小値
    vector<long long> dp(n, INF);
    for(int i=0; i<n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(m);
    for(int i=0; i<m; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), compare);
    vector<long long> a(m);
    for(int i=0; i<m; i++) a[i] = vp[i].second;
    cout << LIS(a) << endl;
    return 0;

}