#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int x, y, z, K;
    cin >> x >> y >> z >> K;
    vector<long long> a(x), b(y), c(z);
    for(int i=0; i<x; i++) cin >> a[i];
    for(int i=0; i<y; i++) cin >> b[i];
    for(int i=0; i<z; i++) cin >> c[i];
    vector<long long> ab;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }

    sort(ab.rbegin(), ab.rend());
    vector<long long> abc;
    for(int i=0; i<min(K, (int)ab.size()); i++) {
        for(int j=0; j<z; j++) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    sort(abc.rbegin(), abc.rend());
    for(int i=0; i<K; i++) cout << abc[i] << endl;
}