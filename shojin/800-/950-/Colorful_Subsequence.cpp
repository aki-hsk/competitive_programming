#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(26, 0);
    long long ans = 1;
    for(int i=0; i<n; i++) v[s[i]-'a']++;

    for(int i=0; i<26; i++) {
        ans *= v[i]+1;
        ans %= mod;
    }
    cout << ans-1 << endl;
}