#include<iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c*d-b <= 0) {
        cout << -1 << endl;
        return 0;
    }
    else cout << (a + (c*d-b)-1)/(c*d-b) << endl;
}