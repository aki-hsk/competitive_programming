#include<iostream>
#include<vector>
#include<map>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
const int MX = 1e6+5;


struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x; }
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
    vector<pair<long long,int>> factor(long long x) {
        vector<pair<long long,int>> res;
        for (int p : primes) {
            int y = 0;
            while (x%p == 0) x /= p, ++y;
            if (y != 0) res.emplace_back(p,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
};

int main() {
    Sieve sieve(MX);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    map<int, int> mp;
    for(int i=0; i<n; i++) {
        auto f = sieve.factor(a[i]);
        for(auto p:f) {
            mp[p.first] = max(mp[p.first], p.second);
        }
    }

    mint lcm = 1;
    for(auto p:mp) {
        for(int i=0; i<p.second; i++) {
            lcm *= p.first;
        }
    }

    mint ans;
    for(int i=0; i<n; i++) {
        mint b = lcm/a[i];
        ans += b;
    }
    cout << ans.val() << endl;
    return 0;
}