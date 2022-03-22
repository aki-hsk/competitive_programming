#include<iostream>
#include<vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> sum_h(h), sum_w(w);
    vector<vector<int>> a(h, vector<int>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) cin >> a[i][j];
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) sum_h[i] += a[i][j];
    }
    for(int j=0; j<w; j++) {
        for(int i=0; i<h; i++) sum_w[j] += a[i][j];
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            printf("%d ", sum_h[i] + sum_w[j] - a[i][j]);
        }
        printf("\n");
    }
}