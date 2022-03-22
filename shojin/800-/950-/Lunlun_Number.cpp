#include<iostream>
#include<vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<long long> a;
    for(int i=1; i<=9; i++) a.push_back(i);

    // whileを一周する間に一桁上がる
    while(true) {
        if(k <= a.size()) {
            cout << a[k-1] << endl;
            return 0;
        }
        k -= a.size();
        vector<long long> old;
        swap(old, a);
        for(long long x:old) {
            for(int i=-1; i<=1; i++) {
                int d = x%10 + i;
                if(d < 0 || d > 9) continue;
                long long nx = x*10+d;
                a.push_back(nx);
            }
        }
    }
    return 0;
}