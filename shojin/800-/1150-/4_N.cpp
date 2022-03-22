#include<iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    for(int b=1; b<=3500; b++) {
        for(int c=1; c<=3500; c++) {
            long long numerator = n*b*c;
            long long denominator = 4*b*c-n*(b+c);
            if(!denominator) continue;
            if(numerator % denominator != 0) continue;
            long long a = numerator / denominator;
            if(a > 0) {
                printf("%d %d %d\n", a, b, c);
                return 0;
            }
        }
    }
}