#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, r;
    string s;
    cin >> n >> r >> s;
    int end_p = 1000, t = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '.') end_p = i;
    }
    for(int i=0; i<n; i++) {
        int d = min(n-1, i+r-1);
        if(s[i] == '.' || d >= end_p) {
            for(int j=i; j<=d; j++) s[j] = 'o';
            t++;
        }
        if(d >= end_p || end_p == 1000) break;
        t++;
    }
    cout << t << endl;
}