#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

string a, b, s, t;
bool same = false;

bool rec(string& s, int d) {
    int n = s.size();
    if(d == 3) return s == t;

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            swap(s[i], s[j]);
            if(rec(s, d+1)) {
                return true;
            }
            swap(s[i], s[j]);
        }
    }
    if(same) {
        if(rec(s, d+1)) return true;
    }
    return false;
}

int main() {
    cin >> a >> b;
    for(int i=0; i<(int)a.size(); i++) {
        if(a[i] != b[i]) {
            s.push_back(a[i]);
            t.push_back(b[i]);
        }
    }
    map<char, int> mp;
    for(int i=0; i<(int)a.size(); i++) {
        mp[a[i]]++;
        if(mp[a[i]] > 1) same = true;
    }

    if(s.size() > 6) {
        cout << "NO" << endl;
        return 0;
    }

    if(rec(s, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}