#include<iostream>
#include<vector>
using namespace std;

void chmin(long long &a, long long b) {
    if(a > b) a = b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    long long ans = (1LL<<60);
    for(int i=0; i<n-k+1; i++) {
        int left = i, right = i+k-1;
        long long val1 = abs(x[left]) + x[right]-x[left];
        long long val2 = abs(x[right]) + x[right]-x[left];
        chmin(ans, min(val1, val2));
    }
    cout << ans << endl;
}