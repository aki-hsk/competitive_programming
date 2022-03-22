#include<iostream>
#include<vector>
using namespace std;

// https://scrapbox.io/Example0911/ARC118_B_Village_of_M_People

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<long long> a(k);
    for(int i=0; i<k; i++) cin >> a[i];

    long long l = -1, r = (1LL<<60);
    while(r-l > 1) {
        long long mid = (l + r)/2;
        long long mi = 0, ma = 0;
        for(int i=0; i<k; i++) {
            mi += (m * a[i] - mid + n - 1) / n;
            ma += (mid + m * a[i]) / n;
        }
        if(mi <= m && m <= ma) r = mid;
        else l = mid;
    }

    vector<long long> b(k);
    long long mid = r;
    long long sum = 0;
    for(int i=0; i<k; i++) {
        b[i] = (m * a[i] - mid + n - 1) / n;
        sum += b[i];
    }
    long long need = m - sum;

    for(int i=0; i<k; i++) {
        if(need > 0) {
            long long now = (mid + m * a[i]) / n - b[i];
            if(now < need) {
                b[i] += now;
                need -= now;
            }
            else {
                b[i] += need;
                need = 0;
            }
        }
        cout << b[i] << " ";
    }
    cout << endl;
}