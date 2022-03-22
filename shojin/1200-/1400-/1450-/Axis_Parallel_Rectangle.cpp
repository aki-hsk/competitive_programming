#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF = 1LL<<60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    long long ans = (1LL<<62);

    for(int l=0; l<n; l++) {
        for(int r=0; r<n; r++) {
            for(int t=0; t<n; t++) {
                for(int b=0; b<n; b++) {
                    if(x[l] > x[r]) continue;
                    if(y[b] > y[t]) continue;
                    int cnt = 0;
                    for(int i=0; i<n; i++) {
                        if(x[l] <= x[i] && x[i] <= x[r] && y[b] <= y[i] && y[i] <= y[t]) {
                            cnt++;
                        }
                    }
                    if(cnt >= k) {
                        ans = min(ans, abs(x[r]-x[l]) * abs(y[t]-y[b]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}