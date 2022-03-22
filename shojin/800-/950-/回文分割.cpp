#include<iostream>
#include<map>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i=0; i<s.size(); i++) mp[s[i]]++;

    int odd_cnt = 0;
    for(auto m:mp) {
        if(m.second&1) odd_cnt++;
    }
    int even_cnt = s.size()-odd_cnt;

    if(odd_cnt == 0) {
        cout << even_cnt << endl;
        return 0;
    }

    int ans = 1;
    // oddに対してeven_cntを２個ずつ配る
    cout << 1 + even_cnt/(odd_cnt*2) * 2 << endl;
}