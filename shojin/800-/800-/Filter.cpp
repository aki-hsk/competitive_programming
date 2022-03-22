#include<iostream>
#include<vector>
#include<regex>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
    string s;
    getline(cin, s);
    vector<string> v;
    istringstream stream(s);
    while(stream >> s) {
        v.push_back(s);
    }


    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    for(int i=0; i<v.size(); i++) {
        bool flg = false;
        for(int j=0; j<n; j++) {
            if(v[i].size() != a[j].size()) continue;
            if(v[i] == a[j]) flg = true;
            bool valid = true;
            for(int k=0; k<v[i].size(); k++) {
                if(a[j][k] == '*') continue;
                if(v[i][k] != a[j][k]) valid = false;
            }
            if(valid) flg = true;
        }
        if(!flg) cout << v[i];
        if(flg) rep(k, v[i].size()) cout << "*";
        cout << endl;
    }
}