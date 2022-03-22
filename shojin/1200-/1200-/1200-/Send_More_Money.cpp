#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;

map<char, int> mp;
ll convert(string t) {
    ll x = 1, res = 0;
    for(int i=t.size()-1; i>=0; i--) {
        res += x*mp[t[i]];
        x *= 10;
        if(i == 0 && mp[t[i]] == 0) {
            res = -1;
            break;
        }
    }
    return res;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    string s = a+b+c;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if(s.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<int> num(10);
    iota(num.begin(), num.end(), 0);

    do {
        for(int i=0; i<s.size(); i++) mp[s[i]] = num[i];
        ll x = convert(a), y = convert(b), z = convert(c);
        if(x == -1 || y == -1 || z == -1) continue;
        if(x + y == z) {
            printf("%lld %lld %lld\n", x, y, z);
            return 0;
        }
    } while (next_permutation(num.begin(), num.end()));
    cout << "UNSOLVABLE" << endl;
}