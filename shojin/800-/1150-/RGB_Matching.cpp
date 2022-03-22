#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<long long> c(3), puppy[3];
    for(int i=0; i<n; i++) {
        long long a;
        char c;
        cin >> a >> c;
        if(c == 'R') puppy[0].push_back(a);
        else if(c == 'G') puppy[1].push_back(a);
        else puppy[2].push_back(a);
    }

    if(puppy[0].size() % 2 == 0 && puppy[1].size() % 2 == 0 && puppy[2].size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    // puppy[2]を偶数にする
    if(puppy[0].size() % 2 == 0) swap(puppy[0], puppy[2]);
    if(puppy[1].size() % 2 == 0) swap(puppy[1], puppy[2]);

    long long ans = (1LL<<60);
    for(int i=0; i<3; i++) sort(puppy[i].begin(), puppy[i].end());

    for(auto a:puppy[0]) {
        auto it = lower_bound(puppy[1].begin(), puppy[1].end(), a);
        if(it != puppy[1].end()) {
            ans = min(ans, *it - a);
        }
        if(it != puppy[1].begin()) {
            it--;
            ans = min(ans, a-*it);
        }
    }

    vector<pair<long long, pair<int, int>>> nearest2[2];

    for(int c = 0; c < 2; c++) {
        for(int i=0; i<puppy[c].size(); i++) {
            long long a = puppy[c][i];
            auto it = lower_bound(puppy[2].begin(), puppy[2].end(), a);
            if(it != puppy[2].end()) nearest2[c].push_back({*it - a, {a, *it}});
            if(it != puppy[2].begin()) {
                it--;
                nearest2[c].push_back({a-*it, {a, *it}});
            }
        }
        sort(nearest2[c].begin(), nearest2[c].end());
    }

    for(int i=0; i<4 && i < nearest2[0].size(); i++) {
        auto a = nearest2[0][i];
        for(int j=0; j<4 && j<nearest2[1].size(); j++) {
            auto b = nearest2[1][j];
            if(a.second.second == b.second.second) continue;
            ans = min(ans, a.first + b.first);
        }
    }
    cout << ans << endl;
}