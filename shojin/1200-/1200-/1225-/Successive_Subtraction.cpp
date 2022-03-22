#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> plus, minus;
    for(int i=0; i<n; i++) {
        if(a[i] >= 0) plus.push_back(a[i]);
        else minus.push_back(a[i]);
    }
    sort(plus.rbegin(), plus.rend());
    sort(minus.begin(), minus.end());
    if(minus.empty()) {
        minus.push_back(plus.back());
        plus.pop_back();
    }
    if(plus.empty()) {
        plus.push_back(minus.back());
        minus.pop_back();
    }

    vector<pair<int, int>> res;
    int cur = minus[0];
    for(int i=0; i+1<plus.size(); i++) {
        res.push_back({cur, plus[i]});
        cur -= plus[i];
    }
    res.push_back({plus.back(), cur});
    cur = plus.back() - cur;

    for(int i=1; i<minus.size(); i++) {
        res.push_back({cur, minus[i]});
        cur -= minus[i];
    }
    cout << cur << endl;
    for(auto p:res) cout << p.first << " " << p.second << endl;
}