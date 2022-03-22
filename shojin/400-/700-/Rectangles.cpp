#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    map<pair<int, int>, int> mp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(p[i].second == p[j].second) {
                int x1 = p[i].first;
                int x2 = p[j].first;
                if(x1 > x2) swap(x1, x2);
                mp[{x1, x2}]++;
            }
        }
    }
    int ans = 0;
    for(auto m:mp) ans += m.second * (m.second - 1) / 2;
    cout << ans << endl;
}