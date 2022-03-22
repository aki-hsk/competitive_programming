#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int op(int x, int y) { return x^y; }
int e() { return 0;}
int main() {
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> t(n);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        t.set(i, a);
    }
    for(int qi=0; qi<q; qi++) {
        int type, x, y;
        cin >> type >> x >> y;
        x--;
        if(type == 1) {
            t.set(x, t.get(x)^y);
        }
        else {
            int ans = t.prod(x, y);
            printf("%d\n", ans);
        }
    }
}