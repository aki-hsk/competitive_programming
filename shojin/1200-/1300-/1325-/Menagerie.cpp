#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<char> ans(n);
    ans[0] = 'S';
    if(s[0] == 'o') {
        ans.back() = 'S';
        ans[1] = 'S';
    }
    else {
        ans.back() = 'W';
        ans[1] = 'S';
    }

    for(int i=1; i<n; i++) {
        char next_c;
        if(ans[i] == 'S') {
            if(s[i] == 'o') {
                if(ans[i-1] == 'S') next_c = 'S';
                else next_c = 'W';
            }
            else {
                if(ans[i-1] == 'S') next_c = 'W';
                else next_c = 'S';
            }
        }
        else if(ans[i] == 'W') {
            if(s[i] == 'o') {
                if(ans[i-1] == 'S') next_c ='W';
                else next_c = 'S';
            }
            else {
                if(ans[i-1] == 'S') next_c = 'S';
                else next_c = 'W';
            }
        }
        if(i == n-1 && ans.back() != next_c) {
            cout << -1 << endl;
            return 0;
        }
        if(i != n-1) ans[i+1] = next_c;
    }
    for(auto a:ans) cout << a;
    cout << endl;
}