#include <bits/stdc++.h>
using namespace std;

long long n;
vector<int> v = {3, 5, 7};
void dfs(long long m, int use, int &ans) {
    if(m > n) return;
    if(v.size() == __builtin_popcount(use)) ans++;
    for(int i=0; i<v.size(); i++) {
        dfs(m*10+v[i], use|(1<<i), ans);
    }
}

int main() {
    cin >> n;
    int ans = 0;
    dfs(0LL, 0b000, ans);
    cout << ans << endl;
}