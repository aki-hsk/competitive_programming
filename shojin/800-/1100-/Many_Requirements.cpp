#include<iostream>
#include<vector>
using namespace std;
int N, M, q;
int p[20];
int ans = 0;
int a[60], b[60], c[60], d[60];

// ○ * 10, | * 9を並べる → 19C9 = 92378
// 92378 * 50 = 4500000くらい -> 全列挙で間に合う!!

void func() {
    int res = 0;
    for(int i=0; i<q; i++) {
        if(p[b[i]-1] - p[a[i]-1] == c[i]) res += d[i];
    }
    ans = max(ans, res);
}

void dfs(int pos, int m) {
    if(pos == N) {
        func();
        return;
    }
    for(int i=m; i<=M; i++) {
        p[pos] = i;
        dfs(pos+1, i);
    }
}

int main() {
    cin >> N >> M >> q;
    for(int i=0; i<q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(0, 1);
    cout << ans << endl;
}