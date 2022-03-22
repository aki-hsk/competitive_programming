#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long left = 0, right = n;
    while(right - left > 1) {
        long long mid = (right + left)/2;
        long long x = mid*(mid+1)/2;
        if(x >= n) right = mid;
        else left = mid;
    }
    int index = left + 1;
    for(int i=index; i>=1; i--) {
        if(n >= i) {
            n -= i;
            cout << i << endl;
        }
        if(n == 0) break;
    }
}