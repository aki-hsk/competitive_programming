#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    reverse(s.begin(), s.end());
    int cur = 0;
    vector<int> ans;
    while(cur < n) {
        int prev = cur;
        for(int i=m; i>=1; i--) {
            if(s[cur+i] == '1') continue;
            if(cur+i > n) continue;
            cur += i;
            ans.push_back(i);
            break;
        }
        if(prev == cur) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto a:ans) cout << a << endl;
}