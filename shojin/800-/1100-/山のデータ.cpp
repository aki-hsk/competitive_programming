#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    int ans = 1, u, s;
    for(int i=0; i<n-1;) {
        u = i;
        while(i < n-1 && h[i] < h[i+1]) i++;
        while(i < n-1 && h[i] > h[i+1]) i++;
        s = i;
        ans = max(ans, s - u + 1);
    }
    cout << ans << endl;
}