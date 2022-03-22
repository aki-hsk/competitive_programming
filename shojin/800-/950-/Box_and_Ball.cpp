#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, 1);
    vector<bool> b(n+1, false);
    b[1] = true;

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        v[x]--;
        v[y]++;
        if(b[x]) b[y] = true;
        if(!v[x]) b[x] = false;
    }

    int ans = 0;
    for(int i=1; i<=n; i++) if(v[i] && b[i]) ans++;
    cout << ans << endl;
}