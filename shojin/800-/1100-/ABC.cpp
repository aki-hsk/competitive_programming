#include<iostream>
using namespace std;

// 転倒数
int main() {
    string s;
    cin >> s;
    int n = s.size();

    long long res = 0;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'A') cnt++;
        else if(s[i] == 'B') {
            if(i+1<n && s[i+1] == 'C') {
                res += cnt;
                i++;
            }
            else cnt = 0;
        }
        else cnt=0;
    }
    cout << res << endl;
}