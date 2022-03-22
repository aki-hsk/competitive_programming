#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<long long> cnt(30, 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<30; j++) {
            if(a[i]>>j&1) cnt[j]++;
        }
    }
    long long ans = accumulate(a.begin(), a.end(), 0LL);

    for(int i=0; i<n; i++) {
        long long sum = 0;
        for(int j=0; j<30; j++) {
            if(~a[i]>>j&1) sum += cnt[j]<<j;
            else sum += (n-cnt[j])<<j;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}