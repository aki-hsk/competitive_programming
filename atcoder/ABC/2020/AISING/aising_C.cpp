#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int h=1; h<=n; h++) {
        int count = 0;
        for(int i=1; i<=100; i++) {
            if(i * i >= h) break;
            for(int j=i; j<=100; j++) {
                for(int k=j; k<=100; k++) {
                    int x = (i*i)+(j*j)+(k*k)+(i*j)+(j*k)+(k*i);
                    if(x == h) {
                        if(i == j && j==k && k==i) {
                            count++;
                        } else if(i!=j && j!=k & k!=i){
                            count += 6;
                        } else {
                            count += 3;
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}