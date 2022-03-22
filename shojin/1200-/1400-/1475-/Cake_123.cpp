#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    int x, y, z, K;
    cin >> x >> y >> z >> K;
    vector<long long> a(x), b(y), c(z);
    for(int i=0; i<x; i++) cin >> a[i];
    for(int i=0; i<y; i++) cin >> b[i];
    for(int i=0; i<z; i++) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());


    vector<long long> ans;
    for(long long i=0; i<x; i++) {
        for(long long j=0; j<y; j++) {
            if(i * j > K) break;
            for(long long k=0; k<z; k++) {
                if(i * j * k > K) break;
                ans.push_back(a[i] + b[j] + c[k]);
            }
        }
    }

    sort(ans.rbegin(), ans.rend());
    for(int i=0; i<K; i++) cout << ans[i] << endl;
}