#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int mod = 1000000007;

void prime_factorization(long long n, map<int, int>& mp) {
    vector<pair<int, int>> res;
    long long m = n;
    for(long long i=2; i*i<=n; i++) {
        int cnt = 0;
        while(m % i == 0) {
            cnt++;
            m /= i;
        }
        if(cnt) mp[i] += cnt;
    }
    if(m > 1) mp[m] += 1;
}


int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> map_a;
    for(int i=n; i>m; i--) {
        prime_factorization(i, map_a);
    }
    long long ans = 1;
    for(auto m:map_a) {
        ans *= (m.second + 1);
        ans %= mod;
    }
    cout << ans << endl;
}