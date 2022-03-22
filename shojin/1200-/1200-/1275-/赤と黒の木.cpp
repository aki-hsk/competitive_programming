#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    int M = 0, cnt = 1;
    for(int i=0; i<n*2-1; i++) {
        if(a[i] == a[i+1]) cnt++;
        else cnt = 1;
        M = max(M, cnt);
    }
    if(M == n*2) cout << -1 << endl;
    else cout << (M-1) / 2 + 1<< endl;
}
