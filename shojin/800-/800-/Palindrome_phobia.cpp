#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> v(3);
    for(int i=0; i<s.size(); i++) {
        v[s[i]-'a']++;
    }
    sort(v.begin(), v.end());
    if(v[2] - v[0] > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}