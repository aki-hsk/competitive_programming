#include<iostream>
#include<vector>
using namespace std;

int a[105][105];
int s[105][105];

int main() {
    int h, w;
    cin >> h >> w;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            int c;
            cin >> c;
            if((i+j) % 2 == 1) c *= -1;
            a[i][j] = c;
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + a[i][j];
        }
    }

    int ans = 0;
    for(int b=0; b<h; b++) {
        for(int t=b+1; t<=h; t++) {
            for(int l=0; l<w; l++) {
                for(int r=l+1; r<=w; r++) {
                    int sum = s[t][r] - s[t][l] - s[b][r] + s[b][l];
                    if(sum == 0) ans = max(ans, (t-b) * (r-l));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}