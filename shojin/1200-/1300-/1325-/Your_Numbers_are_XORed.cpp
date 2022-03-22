#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];

    vector<int> a(n);
    for(int i=0; i<n-1; i++) {
        a[i+1] = a[i] ^ b[i];
    }
    if((a[0] ^ a[n-1]) != b[n-1]) {
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
}