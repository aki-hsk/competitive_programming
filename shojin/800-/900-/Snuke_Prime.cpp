#include<iostream>
#include<vector>
#include<map>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    long long N, C;
    cin >> N >> C;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    map<long long, long long> mp;
    rep(i, N) {
        mp[a[i]] += c[i];
        mp[b[i]+1] -= c[i];
    }

    long long sum = 0;
    long long before = 0;
    long long ans = 0;
    for(auto m:mp) {
        if(sum >= C) {
            ans += C * (m.first - before);
            before = m.first;
        }
        else {
            ans += sum * (m.first - before);
            before = m.first;
        }
        sum += m.second;
    }
    cout << ans << endl;
}