#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    // long longを使おう
    // intの最大値は(1<<31)-1 2147483647 2e9
    // この問題は1e10まで行く
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll sum = 0;
    for(auto m:mp) {
        sum += m.second;
        if(sum >= k) {
            cout << m.first << endl;
            return 0;
        }
    }
}