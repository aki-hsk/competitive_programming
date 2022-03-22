#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;

    string s1 = S.substr(0, N/2);
    string s2 = S.substr(N/2, N/2);
    int count_w = count(s1.begin(), s1.end(), 'W');
    int count_r = count(s2.begin(), s2.end(), 'R');
    ans = min(count_w, count_r);

    cout << ans << endl;
}