#include<iostream>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'a') continue;
        int m = 26 - (s[i]-'a');
        if(k >= m) {
            s[i] = 'a';
            k -= m;
        }
    }
    s.back() = s.back() + k%26;
    cout << s << endl;
}