#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<long long> v, sum(n+1);
    for(int i=0; i<n; i++) sum[i+1] = sum[i] + a[i];
    for(int l=0; l<n; l++) {
        for(int r=l+1; r<=n; r++) {
            v.push_back(sum[r]-sum[l]);
        }
    }

    long long ans = 0;
    for(int i=60; i>=0; i--) {
        vector<long long> nv;
        int cnt = 0;
        for(int j=0; j<v.size(); j++) {
            if(v[j]>>i&1) {
                cnt++;
                nv.push_back(v[j]);
            }
        }
        if(cnt >= k) {
            ans |= (1LL<<i);
            swap(v, nv);
        }
    }
    cout << ans << endl;
    return 0;
}