#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n % 2 == 0) {
        long long mi = a[n/2-1] + a[n/2];
        long long ma = b[n/2-1] + b[n/2];
        cout << ma-mi+1 << endl;
    }
    else {
        long long mi = a[n/2], ma = b[n/2];
        cout << ma-mi+1 << endl;
    }
}