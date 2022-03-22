#include<iostream>
#include<vector>
using namespace std;
const long long INF = 1LL<<61;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    long long left = 0, right = 1e18+1;
    while(right - left > 1) {
        long long mid = (right + left) / 2;
        vector<long long> hp = h;
        for(int i=0; i<n; i++) {
            if(b > INF / mid) {
                hp[i] = 0;
                continue;
            }
            hp[i] -= b * mid;
        }
        long long cnt = 0;
        long long d = a-b;
        for(int i=0; i<n; i++) {
            if(hp[i] <= 0) continue;
            cnt += (hp[i]+d-1)/d;
        }
        if(cnt <= mid) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}