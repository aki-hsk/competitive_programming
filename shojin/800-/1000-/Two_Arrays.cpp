#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    long long biggerA = 0, biggerB = 0;
    for(int i=0; i<n; i++) {
        if(a[i] > b[i]) biggerA += a[i] - b[i];
        if(b[i] > a[i]) biggerB += (b[i]-a[i])/2;
    }
    if(biggerA <= biggerB) cout << "Yes" << endl;
    else cout << "No" << endl;
}