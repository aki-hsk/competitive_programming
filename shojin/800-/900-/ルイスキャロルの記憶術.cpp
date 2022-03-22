#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main() {
    map<char, char> mp;
    mp['b'] = mp['c'] = '1';
    mp['d'] = mp['w'] = '2';
    mp['t'] = mp['j'] = '3';
    mp['f'] = mp['q'] = '4';
    mp['l'] = mp['v'] = '5';
    mp['s'] = mp['x'] = '6';
    mp['p'] = mp['m'] = '7';
    mp['h'] = mp['k'] = '8';
    mp['n'] = mp['g'] = '9';
    mp['z'] = mp['r'] = '0';

    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int cnt = 0;
    for(int i=0; i<n; i++) {
        string s;
        for(int j=0; j<v[i].size(); j++) {
            char c = tolower(v[i][j]);
            if(!mp[c]) continue;
            s.push_back(mp[c]);
        }
        if(s.size() > 0) {
            if(cnt == 0) cout << s;
            else cout << " " << s;
            cnt++;
        }
    }
    cout << endl;
}