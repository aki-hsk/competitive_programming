#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int mod = 1000000007;

long long power(int n) {
    long long res = 1;
    for(int i=0; i<n; i++) {
        res *= 2;
        res %= mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), v(n+1, 0);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        v[a[i]]++;
    }

    if(n&1) {
        bool flg = true;
        if(v[0] != 1) flg = false;
        for(int i=1; i<=n/2; i++) {
            if(i&1 && v[i] != 0) flg = false;
            if(i%2 == 0 && v[i] != 2) flg = false;
        }
        if(flg) cout << power((n-1)/2) << endl;
        else cout << 0 << endl;
        return 0;
    }

    bool flg = true;
    for(int i=0; i<=n/2; i++) {
        if(i&1 && v[i] != 2) flg = false;
        if(i%2 == 0 && v[i] != 0) flg = false;
    }
    if(flg) cout << power(n/2) << endl;
    else cout << 0 << endl;
    return 0;
}