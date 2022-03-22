#include<iostream>
using namespace std;

int cnt[10][10];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        string s = to_string(i);
        int pre = s.front() - '0';
        int suf = s.back() - '0';
        cnt[pre][suf]++;
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        string s = to_string(i);
        int pre = s.front() - '0';
        int suf = s.back() - '0';
        ans += cnt[suf][pre];
    }
    cout << ans << endl;
}