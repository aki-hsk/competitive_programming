#include<iostream>
#include<vector>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> res;
    for(long long i=1; i*i<=n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i*i != n) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> div = divisor(n);
    long long ans = 0;
    // 割り算の操作をする場合
    for(auto d:div) {
        if(d == 1) continue;
        long long m = n;
        while(m % d == 0) {
            m /= d;
        }
        if(m % d == 1) ans++;
    }

    // 割り算の操作を一度もしない場合
    // kがnの約数でないとき
    // n % k == 1  <-> (n-1) % k == 0 (ただし k≠1)
    ans += divisor(n-1).size() - 1;
    cout << ans << endl;
}