#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for(int i=0; i<n/2; i++) {
        if(s[i] == s[n-1-i]) continue;
        else cnt++;
    }
    int ans = n*25;
    if(cnt == 0 && n%2 == 1) ans -= 25;
    if(cnt == 1) ans -= 2;
    cout << ans << endl;
}