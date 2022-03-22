#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 区間スケジューリング問題

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for(int i=0; i<m; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), comp);
    int res = 0;
    int endtime = 0;
    for(int i=0; i<m; i++) {
        if(a[i].first >= endtime) {
            endtime = a[i].second;
            ++res;
        }
    }
    cout << res << endl;
}