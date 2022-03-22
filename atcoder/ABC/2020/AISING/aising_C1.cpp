#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int h=1; h<=n; h++) {
        int count = 0;
        for(int i=1; i<=100; i++) {
            for(int j=i; j<=100; j++) {
                for(int k=j; k<=100; k++) {
                    int x = (i*i)+(j*j)+(k*k)+(i*j)+(j*k)+(k*i);
                    if(x == h) count++;
                }
            }
        }
        cout << count << endl;
    }
}