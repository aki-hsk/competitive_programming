#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long n, x, m;
    cin >> n >> x >> m;
    vector<int> id(m, -1);
    vector<int> a;
    int len = 0;
    long long tot = 0;
    while(id[x] == -1) {
        a.push_back(x);
        id[x] = len;
        len++;
        tot += x;
        x = (x*x)%m;
    }

    // 1周期での長さ
    int c = len - id[x];

    // 1周期分の合計
    long long s = 0;
    for(int i=id[x]; i<len; i++) s += a[i];

    long long ans = 0;
    if(n < len) {
        for(int i=0; i<n; i++) ans += a[i];
        cout << ans << endl;
        return 0;
    }

    ans += tot;
    n -= len;
    ans += s*(n/c);
    n %= c;
    for(int i=0; i<n; i++) ans += a[id[x]+i];
    cout << ans << endl;
}