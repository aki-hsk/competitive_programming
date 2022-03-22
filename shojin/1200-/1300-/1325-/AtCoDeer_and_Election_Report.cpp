#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long A = 1, B = 1;
    for(int i=0; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        long long co = max((A+a-1)/a, (B+b-1)/b);
        A = co * a;
        B = co * b;
    }
    cout << A + B << endl;
}