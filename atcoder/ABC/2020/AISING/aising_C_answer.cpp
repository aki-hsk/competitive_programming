#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans(n+1);
    for(int x=1; x<= 100; x++) {
        for(int y=1; y<= 100; y++) {
            for(int z=1; z<=100; z++) {
                int s = x*x + y*y + z*z;
                s += x*y + y*z + z*x;
                if(s > n) break;
                ans[s]++;
            }
        }
    }

    for(int i=1; 1 <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}