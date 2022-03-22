#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1<<30;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> v(26);
    for(int i=0; i<n; i++) {
        v[s[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++) {
        v[i].push_back(INF);
    }

    string ans = "";
    int cur = -1;
    for(int i=0; i<k; i++) {
        for(int j=0; j<26; j++) {
            int nx = *upper_bound(v[j].begin(), v[j].end(), cur);
            if(nx <= n-k+i) {
                cur = nx;
                ans.push_back(char(j+'a'));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}