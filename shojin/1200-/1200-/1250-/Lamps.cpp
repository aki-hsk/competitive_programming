#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<min(k, 100); i++) {
        vector<int> b(n), sum(n+1);
        swap(a, b);
        for(int j=0; j<n; j++) {
            // ここをfenwicktreeで高速化
            int l = max(0, j-b[j]);
            int r = min(n-1, j+b[j]);
            sum[l]++;
            sum[r+1]--;
        }
        int s = 0;
        for(int j=0; j<n; j++) {
            s += sum[j];
            a[j] = s;
        }
    }

    for(int i=0; i<n; i++) printf("%d ", a[i]);
}