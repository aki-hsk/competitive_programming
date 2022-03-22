#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    long long k = K;
    int i = 0;
    while(k) {
        k /= 2;
        i++;
    }

    long long x = 0;
    while(i--) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(a[j]>>i&1) cnt++;
        }
        if(n - cnt > n/2 && x + pow(2, i) <= K) {
            x += pow(2, i);
        }
    }
    long long ans = 0;
    for(int i=0; i<n; i++) ans += (x ^ a[i]);
    cout << ans << endl;
    return 0;
}