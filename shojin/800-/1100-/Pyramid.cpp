#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i] >> h[i];

    for(int dy=0; dy<=100; dy++) {
        for(int dx=0; dx<=100; dx++) {
            int H = -1;
            for(int i=0; i<n; i++) {
                if(h[i]) {
                    int tmp = h[i] + abs(dx-x[i]) + abs(dy-y[i]);
                    if(H == -1) H = tmp;
                    else if(H != tmp) {
                        H = -2;
                        break;
                    }
                }
            }
            for(int i=0; i<n; i++) {
                if(!h[i]) {
                    int tmp = h[i] + abs(dx-x[i]) + abs(dy-y[i]);
                    if(H > tmp) {
                        H = -2;
                        break;
                    }
                }
            }
            if(H >= 0) {
                cout << dx << " " << dy << " " << H << endl;
                return 0;
            }
        }
    }
}