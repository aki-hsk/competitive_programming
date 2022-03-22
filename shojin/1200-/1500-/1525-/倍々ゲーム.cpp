#include<iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int cnt = 0;
    n = n/2+1;
    while(n > 1) {
        if(cnt % 2 == 1) n = (n+1)/2;
        else n /= 2;
        cnt++;
    }
    if(cnt % 2 == 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
}