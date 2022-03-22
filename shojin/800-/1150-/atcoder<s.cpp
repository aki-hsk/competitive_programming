#include<iostream>
using namespace std;

const int INF = 1<<30;
const string t = "atcoder";

int solve(const string &s) {
    if(s > t) return 0;
    int res = INF;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'a') continue;
        if(i == 1) res = 1;
        else if(s[i] > 't') res = min(res, i-1);
        else res = min(res, i);
    }
    return (res < INF ? res : -1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}