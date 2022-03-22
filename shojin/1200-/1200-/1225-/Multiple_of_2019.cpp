#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int m = 2019;

// 上位桁から見ると10^x上がかからないのでNG

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int x = 1, tot = 0;
    vector<int> cnt(m);
    long long ans = 0;
    for(int i=0; i<n; i++) {
        cnt[tot]++;
        tot += (s[i]-'0') * x;
        tot %= m;
        ans += cnt[tot];
        x = x*10%m;
    }
    cout << ans << endl;
    return 0;
}