#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if(n <= a) {
        cout << "Takahashi" << endl;
    }
    else if(a == b) {
        if(n % (a + 1) == 0) {
            cout << "Aoki" << endl;
        }
        else cout << "Takahashi" << endl;
    }
    else if(a > b) cout << "Takahashi" << endl;
    else if(b > a) cout << "Aoki" << endl;
}