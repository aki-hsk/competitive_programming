#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long res = 0;
    int a_cnt = 0, i = 0;
    while(i<n){
        while(i<n && s[i] == 'A') {
            i++;
            a_cnt++;
        }
        if(s[i] == 'B' && s[i+1] == 'C') {
            res += a_cnt;
            i+=2;
        }
        else {
            a_cnt = 0;
            i++;
        }
    }
    cout << res << endl;
}