#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double n, k;
    cin >> n >> k;
    double x = 1;
    double y = 3*(n-1);
    double z = 6 * (k-1) * (n-k);
    printf("%.20f\n", (x+y+z)/pow(n, 3));
}