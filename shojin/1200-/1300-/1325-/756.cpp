#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

vector<int> num(101, 0);
void prime_factrization(int n) {
    for(int i=2; i<=n; i++) {
        int cnt = 0;
        while(n%i == 0) {
            n /= i;
            cnt++;
        }
        num[i] += cnt;
    }
    if(n >= 2) num[n]++;
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        prime_factrization(i);
    }
    int div75 = 0, div25 = 0, div15 = 0, div5 = 0, div3 = 0;
    rep(i, n+1) {
        if(num[i]+1 >= 75) div75++;
        if(num[i]+1 >= 25) div25++;
        if(num[i]+1 >= 15) div15++;
        if(num[i]+1 >= 5) div5++;
        if(num[i]+1 >= 3) div3++;
    }
    int ans = 0;
    ans += div5 * (div5-1)/2 * max(0, div3-2);
    ans += div15 * max(0, div5-1);
    ans += div25 * max(0, div3-1);
    ans += div75;
    cout << ans << endl;
}