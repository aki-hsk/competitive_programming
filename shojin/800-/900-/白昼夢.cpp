#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    string t = "";
    for(int i=0; i<n; i++) {
        t.push_back(s[i]);
        if(t == "maerd" || t == "esare" || t == "resare" || t == "remaerd") t = "";
    }
    if(t.size() == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}