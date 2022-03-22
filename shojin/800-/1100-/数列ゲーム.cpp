#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int ans = -1000000;

    for(int i=0; i<n; i++) {
        int aoki = -100000, taka = -100000, aoki_sum = 0, taka_sum = 0;
        for(int l=0; l<i; l++) {
            aoki_sum = 0, taka_sum = 0;
            for(int j=l; j<=i; j++) {
                if((j-l)%2 == 0) taka_sum += a[j];
                else aoki_sum += a[j];
            }
            if(aoki_sum > aoki) {
                aoki = aoki_sum;
                taka = taka_sum;
            }
        }

        for(int r=i+1; r<n; r++) {
            aoki_sum = 0, taka_sum = 0;
            for(int j=i; j<=r; j++) {
                if((j-i)%2 == 0) taka_sum += a[j];
                else aoki_sum += a[j];
            }
            if(aoki_sum > aoki) {
                aoki = aoki_sum;
                taka = taka_sum;
            }
        }
        ans = max(ans, taka);
    }
    cout << ans << endl;
}