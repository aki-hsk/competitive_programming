#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int transfomation(map<char, char> mp, string s) {
    rep(i, s.size()) {
        s[i] = mp[s[i]];
    }
    return stoi(s);
}

int main() {
    map<char, char> tr, inverse_tr;
    rep(i, 10) {
        char c;
        cin >> c;
        tr[c] = char(i+'0');
        inverse_tr[i+'0'] = c;
    }
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    rep(i, v.size()) {
        v[i] = transfomation(tr, to_string(v[i]));
    }
    sort(v.begin(), v.end());
    rep(i, v.size()) {
        cout << transfomation(inverse_tr, to_string(v[i])) << endl;
    }
}