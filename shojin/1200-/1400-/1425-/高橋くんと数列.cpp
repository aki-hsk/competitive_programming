#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> v(c);
    for(int i=0; i<c; i++) v[i].push_back(-1);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        a--;
        v[a].push_back(i);
    }
    for(int i=0; i<c; i++) v[i].push_back(n);
    vector<long long> ans(c, (long long)n * (n+1)/2);

    for(int i=0; i<c; i++) {
        for(int j=1; j<v[i].size(); j++) {
            long long len = (v[i][j] - v[i][j-1] - 1);
            ans[i] -= len * (len + 1) / 2;
        }
    }
    for(int i=0; i<c; i++) cout << ans[i] << endl;
    return 0;
}