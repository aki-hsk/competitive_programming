#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(auto &h:H) cin >> h;
    vector<int> W(M);
    for(auto &w:W) cin >> w;
    sort(H.begin(), H.end());
    vector<int> sum1((N+1)/2), sum2((N+1)/2);

    // h[1]-h[0], h[3]-h[2],
    for(int i=0; i+1<N; i+=2) sum1[i/2+1] = sum1[i/2]+H[i+1]-H[i];

    // h[4]-h[3], h[2]-h[1]
    for(int i=N-2; i>0; i-= 2) sum2[i/2] = sum2[i/2+1]+H[i+1]-H[i];

    int ans = (1<<30);
    for(int w:W) {
        int x = lower_bound(H.begin(), H.end(), w) - H.begin();
        cout << x << " " << H[x] << " " << w << endl;
        if(x & 1) x ^= 1;
        cout << x << " " << H[x] << " " << w << endl;
        ans = min(ans, sum1[x/2]+sum2[x/2]+abs(H[x]-w));
    }
    cout << ans << endl;
}