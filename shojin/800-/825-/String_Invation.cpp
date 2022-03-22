#include<iostream>
#include<map>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    long long res = 0;
    for(int i=n-1; i>=1; i--) {
        if(s[i] == s[i-1]) {
            res += n-i-1-mp[s[i]];
            // mapコンテナ内の要素を削除, size()は0になる
            mp.clear();
            mp[s[i]] = n-i-1;
        }
        mp[s[i]]++;
    }
    cout << res << endl;
}