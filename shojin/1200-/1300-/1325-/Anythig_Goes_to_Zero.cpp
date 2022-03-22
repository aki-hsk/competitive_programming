#include<iostream>
#include<vector>
using namespace std;

int f(int x) {
    if(x == 0) return 0;
    return f(x % __builtin_popcount(x)) + 1;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> x(n);
    for(int i=0; i<n; i++) x[i] = s[i]-'0';
    int pc = 0;
    for(int i=0; i<n; i++) pc += x[i];
    vector<int> ans(n);

    for(int b=0; b<2; b++) {
        int npc = pc;
        if(b == 0) npc++;
        else npc--;
        if(npc <= 0) continue;

        // 元のビット列のnpcで割ったあまりを求める
        int r0 = 0;
        for(int i=0; i<n; i++) {
            r0 = r0 * 2 % npc;
            r0 += x[i];
        }

        // ビットが反転したときにnpcで割ったあまりを求める
        int k = 1;
        for(int i=n-1; i>=0; i--) {
            if(x[i] == b) {
                int r = r0;
                if(b == 0) r = (r + k) % npc;
                else r = (r-k+npc) % npc;
                ans[i] = f(r) + 1;
            }
            k = (k * 2) % npc;
        }
    }
    for(int i=0; i<n; i++) cout << ans[i] << endl;
    return 0;
}