#include<iostream>
using namespace std;
long long c[61][61];

int main() {
    int a, b;
    long long k;
    cin >> a >> b >> k;

    // パスカルの三角形
    c[0][0] = 1;
    for(int i=0; i<60; i++) {
        for(int j=0; j<=i; j++) {
            c[i+1][j] += c[i][j];
            c[i+1][j+1] += c[i][j];
        }
    }

    int n = a+b;
    string s;
    for(int i=0; i<n; i++) {
        if(k > c[a+b-1][b]) {
            s.push_back('b');
            k -= c[a+b-1][b];
            b--;
        }
        else {
            s.push_back('a');
            a--;
        }
    }
    cout << s << endl;
}