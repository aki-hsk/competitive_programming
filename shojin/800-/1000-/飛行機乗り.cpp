#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int i = 0, j = 0, t = 0, ans = 0;
    while(true) {
        while(i < n && a[i] < t) i++;
        t = a[i] + x;
        while(j < m && b[j] < t) j++;
        t = b[j] + y;
        if(i >= n || j >= m) break;
        ans++;
    }
    cout << ans << endl;
}