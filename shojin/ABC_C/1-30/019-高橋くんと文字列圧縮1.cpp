#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string t = "";
    t.push_back(s[0]);

    int cnt = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1]) cnt++;
        else {
            // intからcharへの変換 int to char int→char
            t += to_string(cnt);
            t.push_back(s[i]);
            cnt = 1;
        }
    }
    t += to_string(cnt);
    cout << t << endl;
}